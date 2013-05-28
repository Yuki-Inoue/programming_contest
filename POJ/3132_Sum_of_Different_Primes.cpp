
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> primes;

// 4 * 1121 * 15 * 188 is around 11MB < 65MB, the limit.
long dp[1121][15][188];

inline long calc(int n, int k, int pi){
    if (n<0 || k<0 || pi<0)
        return 0;
    else
        return dp[n][k][pi];
}

int main(){

    {
        bool is_prime[1121];
        is_prime[0] = is_prime[1] = false;
        fill(is_prime + 2, is_prime + 1121, true);

        for (int i=2; i<1121; ++i) if (is_prime[i])
            for (int j=i*2; j<1121; j+=i)
                is_prime[j] = false;

        primes.clear();
        for (int i=0; i<1121; ++i) if (is_prime[i])
            primes.push_back(i);
    }
    // primes ready.

    for (int n=0; n<1121; ++n)
        for (int pi=0; pi<188; ++pi)
            dp[n][0][pi] = !n;

    for (int n=0; n<1121; ++n)
        for (int k=1; k<15; ++k)
            for (int pi=0; pi<188; ++pi)
                dp[n][k][pi] =
                (pi == 0 ? 0 : calc(n-primes[pi-1],k-1,pi-1))
                + calc(n,k, pi-1);


    int n,k;
    while (cin >> n >> k && n && k)
        cout << dp[n][k][187] << endl;
}
