
#include <cstdio>
#include <numeric>

int Ans[32][30][30];
int memo[32][30][30];


int n; long k; int m;

inline void mul(const int a[30][30], const int b[30][30], int c[30][30]) {
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j) {
            long sum = 0;
            for (int l=0; l<n; ++l)
                sum += (long) a[i][l] * b[l][j];
            c[i][j] = sum % m;
        }
}

inline void add(const int a[30][30], const int b[30][30], int c[30][30]) {
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
            c[i][j] = (a[i][j] + b[i][j]) % m;
}

int main(){
    scanf(" %d %ld %d", &n, &k, &m);
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j) {
            int d;
            scanf(" %d", &d);
            Ans[0][i][j] = memo[0][i][j] = d % m;
        }

    for (int i=1; i<31; ++i)
        mul(Ans[i-1], Ans[i-1], Ans[i]);

    for (int i=1; i<31; ++i) {
        int upper[30][30];
        mul(Ans[i-1], memo[i-1], upper);
        add(upper, memo[i-1], memo[i]);
    }

    int sum[30][30] = {0};
    for (int i=30; i>=0; i--) {
        long twop = 1 << i;
        if (twop & k) {
            int temp[30][30];
            mul(sum, Ans[i], temp);
            add(temp, memo[i], sum);
        }
    }

    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j) {
            printf("%d", sum[i][j]);
            putchar(j == n-1 ? '\n' : ' ');
        }

}
