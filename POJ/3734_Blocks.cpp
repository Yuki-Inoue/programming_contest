#include <cstdio>

inline long pow2(long l) { return l * l; }

const int modulo = 10007;
int memo[32]; // 2^(2^i)

int exp2(long n){
    int prod = 1;
    for (int i=0; i<31; ++i)
        if ((1<<i) & n)
            prod = (long) prod * memo[i] % modulo;
    return prod;
}

int main(){

    memo[0] = 2;
    for (int i=1; i<32; ++i)
        memo[i] = pow2(memo[i-1]) % modulo;

    int T; scanf(" %d", &T);
    while (T--) {
        long N; scanf(" %ld", &N);
        printf("%d\n", (exp2(N-1)+exp2(2*(N-1))) % modulo);
    }
}
