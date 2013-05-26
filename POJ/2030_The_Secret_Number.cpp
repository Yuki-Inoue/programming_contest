
#include <utility>
#include <string>
#include <iostream>

using namespace std;

typedef std::pair<int,int> P;

int W,H;
int table[80][80];
string code[80];
bool from_right[80][80];

int value(P p){
    return table[p.first][p.second];
}

char getcode(P p){
    return code[p.first][p.second];
}

inline bool valid(P p){
    return p.first >= 0 && p.second >= 0 && p.first < H && p.second < W;
}

P from_point(P p){
    if (from_right[p.first][p.second]) {
        return make_pair(p.first, p.second + 1);
    }
    return make_pair(p.first+1, p.second);
}

// secret number -> sn
// prerequisite: same length
bool sn_less(P p1, P p2){
    do {
        char c1 = code[p1.first][p1.second];
        char c2 = code[p2.first][p2.second];
        if (c1 < c2) {
            return true;
        }
        if (c1 > c2) {
            return false;
        }
        p1 = from_point(p1);
        p2 = from_point(p2);
    }
    while (valid(p1) && valid(p2) && p1 != p2);
    return false;
}



int main(){
    while (cin >> W >> H && W && H) {
        for (int i=0; i<H; ++i) {
            cin >> code[i];
        }

        // table fill
        for (int i=H-1; i>= 0; i--) {
            for(int j=W-1; j>= 0; j--) {
                if (i == H-1 && j==W-1) {
                    table[i][j] = !!isdigit(code[i][j]);
                }
                else if (i == H-1){
                    table[i][j] =
                    !isdigit(code[i][j]) ? 0 : table[i][j+1] + 1;
                    from_right[i][j] = true;
                }
                else if (j== W-1) {
                    table[i][j] =
                    !isdigit(code[i][j]) ? 0: table[i+1][j] + 1;
                    from_right[i][j] = false;
                }
                else if (table[i][j+1] < table[i+1][j] ||
                         (table[i][j+1] == table[i+1][j] &&
                         sn_less(make_pair(i, j+1), make_pair(i+1, j)))){
                    table[i][j] =
                    !isdigit(code[i][j]) ? 0 : table[i+1][j] + 1;
                    from_right[i][j] = false;
                }
                else {
                    table[i][j] =
                    !isdigit(code[i][j]) ? 0 : table[i][j+1] + 1;
                    from_right[i][j] = true;
                }
            }
        }

        int max_val = 0;
        P maxarg = P(-1,-1);
        for (int i=0; i<H; ++i) {
            for (int j=0; j<W; ++j) {
                if (getcode(make_pair(i, j)) != '0' &&
                    (table[i][j] > max_val ||
                     (maxarg.first >= 0 && table[i][j] == max_val &&
                      sn_less(maxarg, make_pair(i, j))))) {

                         maxarg = make_pair(i, j);
                         max_val = table[i][j];
                }
            }
        }

        while (valid(maxarg) && value(maxarg) > 0) {
            char c = getcode(maxarg);
            putchar(c);
            maxarg = from_point(maxarg);
        }
        puts("");
    }
}
