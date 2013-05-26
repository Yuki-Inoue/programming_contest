

#include <iostream>
#include <utility>
#include <climits>

using namespace std;

enum { ICE, BLOCK, START, GOAL };

typedef pair<int,int> P;

int H,W;
int field[20][20];

int best_move;

P dirs[4];

P operator+(const P &p1, const P &p2){
    return make_pair(p1.first + p2.first, p1.second + p2.second);
}

P operator-(const P &p1, const P &p2){
    return make_pair(p1.first - p2.first, p1.second - p2.second);
}

P &operator+=(P &p1, const P &p2){
    p1.first += p2.first;
    p1.second += p2.second;
    return p1;
}

inline bool on_field(const P &p){
    return p.first >= 0 && p.second >= 0 && p.first < H && p.second < W;
}

inline int getfield(const P &p){
    return field[p.first][p.second];
}

inline bool movable(const P &p){
    return on_field(p) && getfield(p) != BLOCK;
}

inline bool passable(const P &p){
    return getfield(p) != GOAL && movable(p);
}

inline void game_search(P stone_p, int t);

void game_search_dir(int dir, P stone_p, int t){
    ++t;
    if (best_move <= t || t > 10) return;

    const P &dirp = dirs[dir];
    P next_p = stone_p + dirp;
    if (!movable(next_p)) return;

    while (passable(next_p)) {
        next_p += dirp;
    }


    if (!on_field(next_p)) return;
    switch (getfield(next_p)) {
        case GOAL:
            best_move = t;
            break;
        case BLOCK:
            field[next_p.first][next_p.second] = ICE;
            game_search(next_p - dirp, t);
            field[next_p.first][next_p.second] = BLOCK;
            break;
        case ICE: case START: ;
    }
}

// t_remain : must be positive on entrance
inline void game_search(P stone_p, int t) {
    for (int i=0; i<4; ++i)
        game_search_dir(i, stone_p, t);
}

int main(){

    dirs[0] = make_pair(0, 1);
    dirs[1] = make_pair(1, 0);
    dirs[2] = make_pair(0, -1);
    dirs[3] = make_pair(-1, 0);

    while (cin >> W >> H && W && H) {
        P stone_p;
        for (int h=0; h<H; ++h) {
            for (int w=0; w<W; ++w) {
                cin >> field[h][w];
                if (field[h][w] == START) {
                    stone_p = make_pair(h,w);
                }
            }
        }
        // start_position and field parsed.

        best_move = INT_MAX;
        game_search(stone_p, 0);
        cout << (best_move < INT_MAX ? best_move : -1) << endl;
    }
}
