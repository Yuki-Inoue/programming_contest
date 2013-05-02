#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int L;
    cin >> L;
    for (int l=1; l<=L; ++l) {
        double x,y;
        cin >> x >> y;
        const double r2 = x * x + y * y;
        const double area = r2 * M_PI / 2;
        const int years = static_cast<int>(area / 50.0) + 1;
        printf("Property %d: This property will begin eroding in year %d.\n",
               l, years);
    }
    printf("END OF OUTPUT.\n");
}
