#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>


inline double pow2(double d){
    return  d* d;
}


int main(){
    int C;
    scanf(" %d", &C);
    while (C--) {
        int N, H, R, T;
        scanf(" %d %d %d %d", &N, &H, &R, &T);

        const double half_interval = sqrt((double)H / 5.0);
        const double interval = 2 * half_interval;

        std::vector<double> positions(N);
        for (int i=0; i<N; ++i) {
            if (T <= i)
                positions[i] = H;
            else {
                double offset = fmod((double)T-i, interval);
                if (offset >= half_interval)
                    offset -= interval;
                positions[i] = H - 5 * pow2(offset);
            }
        }

        sort(positions.begin(), positions.end());
        for (int i=0; i<N; ++i) {
            positions[i] += 0.02*R*i;
        }

        for (int i=0; i<positions.size()-1; ++i)
            printf("%.2f ", positions[i]);
        printf("%.2f\n", positions.back());
    }
}
