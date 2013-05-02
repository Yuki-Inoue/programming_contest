#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int T;
    cin >> T;
    for (int t=0; t<T; ++t) {
        long initial;
        int years;
        int num_ops;
        cin >> initial >> years >> num_ops;
        int max_money = -1;
        for (int op=0; op<num_ops; ++op) {
            int is_compound;
            double interest;
            int cost;
            cin >> is_compound >> interest >> cost;
            int current = initial;
            if (is_compound) {
                for (int year = 0; year<years; ++year) {
                    current += (current * interest) - cost;
                }
            }
            else {
                int accum = 0;
                for (int year=0; year<years; ++year) {
                    accum += (current * interest);
                    current -= cost;
                }
                current += accum;
            }
            max_money = max(max_money, current);
        }
        cout << max_money << endl;
    }
}
