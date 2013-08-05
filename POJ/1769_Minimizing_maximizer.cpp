#include <cstdio>
#include <climits>
#include <algorithm>

// m sorters -> 1..v sortable
long reachable_count[50001];


void update(long ikp1, long jk, long s, long t) {
    if (ikp1 <= s) {
        if (reachable_count[t] <= jk) {
            reachable_count[s] = reachable_count[t] = jk;
            return;
        }
        else if (reachable_count[s] >= jk) {
            return;
        }
    }
    if (ikp1 > t) {
        return;
    }
    long m = (s+t)/2;
    if (reachable_count[s] == reachable_count[t])
        reachable_count[m] = reachable_count[m+1] = reachable_count[s];

    update(ikp1, jk, s, m);
    update(ikp1, jk, m+1, t);
}

long find_ikp1(long ik, long jk, long s, long t) {
    if (reachable_count[s] >= ik) {
        return s+1;
    }
    if (reachable_count[t] < ik) {
        return LONG_MAX;
    }
    long m = (s+t)/2;
    if (reachable_count[s] == reachable_count[t]) {
        reachable_count[m] = reachable_count[m+1] = reachable_count[s];
    }
    return std::min(find_ikp1(ik, jk, s, m), find_ikp1(ik, jk, m+1, t));
}


int main(){
    reachable_count[0] = reachable_count[50000] = 1;
    long n,m;
    scanf(" %ld %ld", &n, &m);
    for (long i=0; i<m; ++i) {
        long ik, jk;
        scanf(" %ld %ld", &ik, &jk);
        update(find_ikp1(ik, jk, 0, n), jk, 0, n);
    }
    printf("%ld\n", find_ikp1(n, n, 0, n)-1);
}
