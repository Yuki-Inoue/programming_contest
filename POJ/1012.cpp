#include <iostream>

using namespace std;

inline bool test(int k, int m){
    int current = 0;
    for (int i=0; i<k; ++i) {
        current = (current + m - 1) % (2*k-i);
        if (current < k) {
            return false;
        }
    }
    return true;
}

int solve(int k) {
    int i=0;
    int j=k;
    while (!test(k,2*k*i+j+1)) {
        ++j;
        if (j==2*k) {
            j=k;
            ++i;
        }
    }
    return 2*k*i+j+1;
}


/*
int main(){
    int k;
    while (cin >> k && k)
        solve(k);
}
*/
/*
int main(){
    for (int k=1; k<14; ++k) {
        cout << "k: " << endl;
        solve(k);
        cout << endl;
    }
}*/


int main(){
    int answers[14];
    for (int k=1; k<14; ++k) {
        answers[k] = solve(k);
    }
    int k;
    while (cin >> k && k)
        cout << answers[k] << endl;
}
