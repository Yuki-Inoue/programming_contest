#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int R, n;
    while (cin >> R >> n && R >= 0) {
        std::vector<int> troops(n);
        for (int i=0; i<n; ++i)
            cin >> troops[i];
        sort(troops.begin(), troops.end());
        int last_range = -10000;
        int palantir = 0;
        int i=0;
        while (true) {
            while (i<n && troops[i] <= last_range)
                ++i;
            if (i==n) break;

            int uncovered_from = troops[i++];
            while (i<n && troops[i] <= uncovered_from + R)
                ++i;
            if (i==n) {
                ++palantir;
                break;
            }

            last_range = troops[i-1] + R;
            ++palantir;
        }
        cout << palantir << endl;
    }
}
