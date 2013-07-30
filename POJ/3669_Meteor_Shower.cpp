#include <cstdio>
#include <climits>
#include <queue>

int field[302][302];

struct QueueEntry {
    int t, x, y;
    QueueEntry(int t_, int x_, int y_)
    : t(t_), x(x_), y(y_) {}
};


inline bool cordinate_valid(int x, int y){
    return x >= 0 && y >= 0;
}


void destroy_field(int x, int y, int t){
    if (cordinate_valid(x, y) && field[x][y] > t)
        field[x][y] = t;
}

std::queue<QueueEntry> entries;

void try_add_entry(int t, int x, int y){
    if (cordinate_valid(x, y) &&
        (x >= 302 || y >= 302 || field[x][y] > t))
        entries.push(QueueEntry(t,x,y));
}

int main(){
    int M;
    scanf(" %d", &M);
    for (int i=0; i<302; ++i)
        for (int j=0; j<302; ++j)
            field[i][j] = INT_MAX;

    for (int i=0; i<M; ++i) {
        int Xi, Yi, Ti;
        scanf(" %d %d %d", &Xi, &Yi, &Ti);
        destroy_field(Xi, Yi, Ti);
        destroy_field(Xi+1, Yi, Ti);
        destroy_field(Xi-1, Yi, Ti);
        destroy_field(Xi, Yi+1, Ti);
        destroy_field(Xi, Yi-1, Ti);
    }


    entries.push(QueueEntry(0,0,0));

    while (!entries.empty()) {
        int x,y,t;
        x = entries.front().x;
        y = entries.front().y;
        t = entries.front().t;
        entries.pop();

        if (x >= 302 || y >= 302 || field[x][y] == INT_MAX) {
            printf("%d\n", t);
            return 0;
        }

        if (field[x][y] <= t)
            continue;

        field[x][y] = t;
        try_add_entry(t+1, x+1, y);
        try_add_entry(t+1, x-1, y);
        try_add_entry(t+1, x, y+1);
        try_add_entry(t+1, x, y-1);
    }

    puts("-1");
}
