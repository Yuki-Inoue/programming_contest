#include <iostream>

using namespace std;

int main(){
    double sum = 0.0;
    for (int m = 0; m<12; ++m) {
        double income;
        cin >> income;
        sum += income;
    }
    const double average = sum / 12;
    cout << "$" <<
    static_cast<double>(static_cast<int>(average*100+0.5))/100 << endl;
}
