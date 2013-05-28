#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>

using namespace std;

int main(){
    int H,W;
    cin >> H >> W;

    vector<string> field;
    for (int h=0; h<H; ++h) {
        field.push_back("");
        cin >> field.back();
    }

    int c=0;

    while (true) {
        int h,w;
        for (h=0; h<H; ++h) for (w=0; w<W; ++w)
            if (field[h][w] == 'W')
                goto HWDetermined;

    HWDetermined:
        if (h==H) break;

        ++c;

        queue<pair<int,int> > q;
        q.push(make_pair(h, w));
        while (!q.empty()) {
            h = q.front().first;
            w = q.front().second;
            q.pop();

            if(h < 0 || h >= H || w < 0 || w >= W || field[h][w] == '.') continue;

            field[h][w] = '.';
            q.push(make_pair(h, w+1));
            q.push(make_pair(h, w-1));
            q.push(make_pair(h+1, w));
            q.push(make_pair(h-1, w));
            q.push(make_pair(h+1, w+1));
            q.push(make_pair(h-1, w+1));
            q.push(make_pair(h+1, w-1));
            q.push(make_pair(h-1, w-1));
        }
    }
    cout << c << endl;
}
