#include <iostream>

long gcd_main(long a, long b){
    long c = a%b;
    return !c ? b : gcd_main(b,c);
}

long gcd(long a, long b){
    return a>=b ?
    gcd_main(a,b) : gcd_main(b,a);
}




// p/q > prev_v/prev_a + n/current
// p > q * (prev_v / prev_a + n / current )
// p * prev_a * current  > q * (prev_v * current + n * prev_a )


// p/q <= prev_v/prev_a + n/current
// current * (p/q - prev_v/prev_a) <= n
// current * (p * prev_a - prev_v * q) <= n * q * prev_a
// current <= n * q * prev_a / (p * prev_a - prev_v * q)


// p/q < prev_v / prev_a
// prev_a * p < prev_v * q


long accum;

// unit: numerator == 1 && denom == positive
// assume: p and q are mutualy prime
// now we use n as remaining
void calculate(long p, long q, long prev_v, long prev_a, long a, long n, long current_denom) {
    if (prev_a > a || n < 0
        || prev_a * p < prev_v * q) return;
    if (prev_a % q == 0 && p * (prev_a/q) == prev_v) {
        accum++;
        return;
    }

    // current <= n * q * prev_a / (p * prev_a - prev_v * q)

    const long const_n =(p*prev_a - prev_v * q);
    for (long i = current_denom; i * const_n <= n*q*prev_a; ++i) {
        long next_a = prev_a * i;
        if (next_a > a) {
            break;
        }
        calculate(p, q, prev_v * i + prev_a, next_a, a, n-1, i);
    }
}


void calculate(long p, long q, long a, long n){
    const long d = gcd(p,q);
    q /= d;
    p /= d;
    accum = 0;
    calculate(p, q, 0, 1, a, n, 1);
}

int main(){
    long p,q,a,n;

    while (std::cin >> p >> q >> a >> n && p && q && a && n) {
        calculate(p, q, a, n);
        printf("%ld\n", accum);
    }
}
