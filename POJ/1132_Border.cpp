
#include <utility>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef pair<int, int> P;


P &operator+=(P &p1, const P &p2){
    p1.first += p2.first;
    p1.second += p2.second;
    return p1;
}

istream &operator>>(istream &is, P &p){
    is >> p.second >> p.first;
    return is;
}


P filled_block(const P &start, char dir){
    switch (dir) {
        case 'N':
            return start;
        case 'S':
            return P(start.first-1, start.second-1);
        case 'E':
            return P(start.first-1, start.second);
        case 'W':
            return P(start.first, start.second-1);
    }
}

int main(){
    int T;
    cin >> T;
    for(int t=1; t<=T; ++t){
        cout << "Bitmap #" << t << endl;
        P p;
        cin >> p;
        char dir;
        vector<string> field(32, string(32, '.'));
        while (cin >> dir && dir != '.') {
            P fill = filled_block(p, dir);
            field[fill.first][fill.second] = 'X';
            switch (dir) {
                case 'N':
                    p += P(1,0);
                    break;
                case 'S':
                    p += P(-1,0);
                    break;
                case 'E':
                    p += P(0,1);
                    break;
                case 'W':
                    p += P(0,-1);
                    break;
            }
        }
        for (int i=31; i>=0; --i)
            cout << field[i] << endl;
        cout << endl;
    }
}
