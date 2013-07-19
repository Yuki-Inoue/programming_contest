#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--) {
        long N, S;
        cin >> N >> S;
        vector<int> numbers(N);
        for (int i=0; i<N; ++i)
            cin >> numbers[i];

        long start = 0, end = 0;
        long total = 0;
        long minimum = LONG_MAX;
        while (true) {
            while (total < S && end < numbers.size())
                total += numbers[end++];
            if (total < S) break;
            while (total >= S)
                total -= numbers[start++];
            minimum = min(minimum, end - start + 1);
        }

        cout << (minimum == LONG_MAX ? 0 : minimum) << endl;
    }
}