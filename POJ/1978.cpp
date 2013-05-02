#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main(){
    int n, r;
    while (cin >> n >> r) {
        if (!r) {
            break;
        }
        vector<pair<int,int> > cuts;
        for (int i=0; i<r; ++i) {
            int p,c;
            cin >> p >> c;
            cuts.push_back(std::make_pair(p,c));
        }
        int fin_top_pos = n;
        while (!cuts.empty()) {
            int p,c;
            p = cuts.back().first;
            c = cuts.back().second;
            cuts.pop_back();
            const int top_offset = n - fin_top_pos;
            if (top_offset < c) {
                fin_top_pos -= p - 1;
            }
            else if(top_offset < c+p-1) {
                fin_top_pos += c;
            }
        }
        cout << fin_top_pos << endl;
    }
}