#include <iostream>
#include <cmath>

int gcd_main(int a, int b){
    int c = a%b;
    return !c ? b : gcd_main(b,c);
}

int gcd(int a, int b){
    return a>=b ?
    gcd_main(a,b) : gcd_main(b,a);
}

int main(){
    int a,b;
    bool start = true;
    while (std::cin >> a >> b) {
        if (!start) {
            printf("\n");
        }
        start = false;
        int d = gcd(a,b);
        a /= d; b /= d;

        const double exact = (double)a / (double)b;
        double diff = 1.0;
        for (int i=1; i<b; ++i) {
            int j =
            static_cast<int>(exact * i + 0.5);
            const double candidate
            = (double)j / (double)i;
            const double cand_diff
            = fabs(candidate - exact);
            if (cand_diff < diff) {
                printf("%d/%d\n", j,i);
                diff = cand_diff;
            }
        }
        printf("%d/%d\n", a,b);
    }
}