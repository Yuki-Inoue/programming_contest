#include <iostream>
#include <vector>
#include <algorithm> // max

using namespace std;


int main(){
    int N;
    while (cin >> N && N) {
        int W,H;
        cin >> W >> H;
        vector<vector<int> >
        board(W+1, vector<int>(H+1, 0));
        for (int i=0; i<N; ++i) {
            int w,h;
            cin >> w >> h;
            board[w][h] = 1;
        }
        for (int i=1; i<W+1; ++i)
            board[i][0] += board[i-1][0];
        for (int i=1; i<H+1; ++i)
            board[0][i] += board[0][i-1];
        for (int i=1; i<W+1; ++i) for (int j=1; j<H+1; ++j)
            board[i][j] += board[i-1][j] + board[i][j-1] - board[i-1][j-1];

        int s,t;
        cin >> s >> t;

        int max_value = 0;
        for (int i=0; i<=W-s; ++i) for(int j=0; j<=H-t; ++j)
            max_value =
            max(max_value,
                board[i+s][j+t]
                - board[i][j+t] - board[i+s][j]
                + board[i][j]);
        cout << max_value << endl;
    }
}