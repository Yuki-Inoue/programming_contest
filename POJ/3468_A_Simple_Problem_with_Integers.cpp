#include <algorithm>
#include <cstdio>

const long TREE_SIZE = 1 << 18;

long long sum[TREE_SIZE];
long long bias[TREE_SIZE];

long A[100001];


inline long intersection(long a, long b, long s, long t){
    long candidate =
    std::min(b,t) - std::max(a,s) + 1;
    return candidate >= 0 ? candidate : 0;
}


void init(long v, long s, long t){
    if (s == t) {
        sum[v] = A[s];
        bias[v] = A[s];
    }
    else {
        bias[v] = 0;
        long m = (s+t)/2;
        long chl = 2*v+1;
        long chr = 2*v+2;
        init(chl, s, m);
        init(chr, m+1, t);
        sum[v] = sum[chl] + sum[chr];
    }
}


// op is add c to [a,b],
// where this call handles [s,t].
// current index is v.
void add(long a, long b, int c, long v, long s, long t){
    if (b < s || a > t) return;
    if (a <= s && b >= t) {
        bias[v] += c;
        sum [v] += (long long) c * (t-s+1);
        return;
    }
    long m = (s+t)/2;
    sum[v] += (long long)intersection(a, b, s, t) * c;
    add(a, b, c, 2*v+1, s, m);
    add(a, b, c, 2*v+2, m+1, t);
}

long long query(long a, long b, long v, long s, long t){
    if (b<s || a>t) return 0;
    if (a <= s && b >= t)
        return sum[v];
    long m = (s+t)/2;
    return
    query(a, b, 2*v+1, s, m) +
    query(a, b, 2*v+2, m+1, t) +
    bias[v] * intersection(a, b, s, t);
}

int main(){
    long N, Q;
    scanf(" %ld %ld", &N, &Q);
    for (long i=1; i<=N; ++i)
        scanf(" %ld", A+i);

    init(0, 1, N);

    for (long i=0; i<Q; ++i) {
        char command;
        scanf(" %c", &command);
        if (command == 'Q') {
            long a, b;
            scanf(" %ld %ld", &a, &b);
            printf("%lld\n", query(a, b, 0, 1, N));
        }
        else {
            long a, b; int c;
            scanf(" %ld %ld %d", &a, &b, &c);
            add(a, b, c, 0, 1, N);
        }
    }
}
