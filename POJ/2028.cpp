#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N,Q;
    while (cin >> N >> Q) {
        if (!N && !Q) {
            break;
        }
        int max_day;
        int max_num = -1;
        vector<int> possible_dates(100,0);
        for (int n=0; n<N; ++n) {
            int M;
            cin >> M;
            for (int m=0; m<M; ++m) {
                int day;
                cin >> day;
                possible_dates[day]++;
            }
        }
        for (int i=0; i<possible_dates.size(); ++i) {
            if (possible_dates[i] > max_num) {
                max_num = possible_dates[i];
                max_day = i;
            }
        }
        cout << (max_num >= Q ? max_day : 0) << endl;
    }
}