#include <cstdio>
#include <complex>
#include <vector>

#include <cmath>

typedef std::complex<double> P;


const double PI = 4*atan(1.0);
const long TREE_SIZE = 1 << 15;


P positions[TREE_SIZE];
double angles[TREE_SIZE];
double rel_angles[10000];
int lengths[10001];

void init(int v, int l, int r){
    if (l+1 == r) {
        positions[v] = lengths[l];
        return;
    }
    angles[v] = 0.0;
    int chl = v*2+1, chr = v*2+2;
    int m = (l+r)/2;
    init(chl, l, m);
    init(chr, m, r);
    positions[v] = positions[chl] + positions[chr];
}

void rotate(int s, double a, int v, int l, int r) {
    if (s <= l || s >= r) return;
    int m = (l+r)/2;
    int chl = 2*v+1, chr = 2*v+2;
    rotate(s, a, chl, l, m);
    rotate(s, a, chr, m, r);
    if (s <= m) angles[v] += a;
    positions[v] = positions[chl]
    + std::polar(1.0, angles[v]) * positions[chr];
}


int main(){
    int n;
    long c;
    while (scanf(" %d %ld", &n, &c) != EOF) {

        // put newline if needed
        {
            static bool first_loop = true;
            if (first_loop)
                first_loop = false;
            else
                puts("");
        }

        for (int i=0; i<n; ++i) {
            int li; scanf(" %d", &li);
            lengths[i] = li;
        }
        for (int i=0; i<n-1; ++i)
            rel_angles[i] = PI;


        init(0, 0, n);

        for (long i=0; i<c; ++i) {
            int s,a; scanf(" %d %d", &s, &a);
            double da = (double)a/180 * PI;
            rotate(s, da-rel_angles[s-1], 0, 0, n);
            rel_angles[s-1] = da;

            printf("%.2lf %.2lf\n", -positions[0].imag(), positions[0].real());
        }
    }
}
