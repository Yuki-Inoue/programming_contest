#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<double> array(300);
    array[0] = 0.0;
    array[1] = 0.5;
    for (int i=2; i<300; ++i) {
        array[i] = array[i-1] + 1.0 / (i+1);
    }
    double in;
    while (1) {
        cin >> in;
        if (!in) {
            break;
        }
        cout <<
        lower_bound(array.begin(), array.end(), in) - array.begin()
        << " card(s)" << endl;
    }
}
