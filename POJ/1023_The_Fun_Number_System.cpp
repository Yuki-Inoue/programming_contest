#include <iostream>
#include <string>

using namespace std;


inline bool in_range(long long n, unsigned long long lower, unsigned long long upper){
    if (n>=0)
        return n <= upper;
    else
        return -n <= lower;
}


int main(){
    int t;
    cin >> t;

    while (t--) {
        int k;
        cin >> k;
        string pns;
        cin >> pns;

        unsigned long long lower = 0, upper = 0;
        for (int i=0; i<k; ++i) {
            upper <<= 1;
            upper += (pns[i] == 'p');
            lower <<= 1;
            lower += (pns[i] == 'n');
        }

        long long N;
        cin >> N;

        if (!in_range(N, lower, upper)) {
            cout << "Impossible" << endl;
            continue;
        }

        for (int i=0; i<k; ++i) {
            unsigned long long next_bit = 1;
            next_bit <<= k-i-1;

            (pns[i]=='p' ? upper : lower) -= next_bit;
            if (in_range(N, lower, upper)) {
                cout << '0';
            }
            else {
                cout << '1';
                N += (pns[i]=='p' ? -next_bit : (long long) next_bit);
            }
        }
        cout << endl;
    }
}
