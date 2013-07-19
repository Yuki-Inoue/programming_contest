#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

inline bool valid(long d, long C, const vector<long> &stalls){
    long x = LONG_MIN;
    for (int i=0; i<stalls.size() && C; ++i) {
        if (stalls[i] < x+d) continue;
        x = stalls[i];
        C--;
    }
    return !C;
}

int main(){
    long N,C;
    cin >> N >> C;
    vector<long> stalls(N);
    while (N--)
        cin >> stalls[N];

    sort(stalls.begin(), stalls.end());

    long lb = 0, ub = (stalls.back() - stalls.front()) / (C-1) + 1;
    while (ub - lb > 1) {
        long mid = (ub+lb)/2;
        if (valid(mid,C,stalls))
            lb = mid;
        else
            ub = mid;
    }
    cout << lb << endl;
}
