#include <iostream>
#include <cstdio>

int H,W;

int count;
char field[20][20];

void recursive(int h, int w) {
    if (h<0 || h>= H || w < 0 || w>=W || field[h][w] == '#') {
        return;
    }

    ++count;
    field[h][w] = '#';

    recursive(h-1, w);
    recursive(h+1, w);
    recursive(h, w+1);
    recursive(h, w-1);
}

int main(){
    while (std::cin >> W >> H && W && H) {
        count = 0;
        int initw, inith;
        for (int i=0; i<H; ++i) for(int j=0; j<W; ++j) {
            char c;
            std::cin >> c;
            if (c == '@') {
                inith = i;
                initw = j;
                c = '.';
            }
            field[i][j] = c;
        }
        recursive(inith, initw);
        printf("%d\n", count);
    }
}
