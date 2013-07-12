#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main(){
    long t;
    cin >> t;
    while (t--) {
        long l,n;
        cin >> l >> n;
        long shortest = LONG_MIN, longest = LONG_MIN;
        for (long i=0; i<n; ++i) {
            long a;
            cin >> a;
            long a_ = l - a;
            shortest = max(shortest, min(a,a_));
            longest = max(longest, max(a,a_));
        }
        cout << shortest << ' ' << longest << endl;
    }
}
