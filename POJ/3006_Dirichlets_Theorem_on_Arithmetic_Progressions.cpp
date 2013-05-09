
#include <vector>
#include <iostream>

using namespace std;

const long the_upper_limit = 1000000;

vector<bool> primes(the_upper_limit,true);

int main(){
    primes[1] = false;
    for (long i=2; i<the_upper_limit; ++i) if(primes[i])
        for (long j=2*i; j<the_upper_limit; j+=i)
            primes[j] = false;


    long a,d,n;
    while (cin >> a >> d >> n && a && d && n) {
        while (true) {
            if (primes[a]) {
                n--;
                if (!n) break;
            }
            a += d;
        }
        cout << a << endl;
    }
}
