#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<long> > Field;

int main(){
    int N;
    cin >> N;
    Field field(N, vector<long>(N,0));
    for (int i=0; i<N; ++i)
        for (int j=0; j<N; ++j)
            cin >> field[i][j];

    Field sum_field(N+1, vector<long>(N+1,0));
    for (int i=0; i<N; ++i)
        for (int j=0; j<N; ++j)
            sum_field[i+1][j+1] =
            field[i][j] +
            sum_field[i+1][j] + sum_field[i][j+1]
            - sum_field[i][j];


    long max_num = 0;
    for (int starti=0; starti<N; ++starti)
        for (int startj=0; startj<N; ++startj)
            for (int endi=starti+1; endi<=N; ++endi)
                for (int endj=startj+1; endj<=N; ++endj)
                    max_num =
                    max(max_num,
                        sum_field[endi][endj]
                        - sum_field[endi][startj]
                        - sum_field[starti][endj]
                        + sum_field[starti][startj]);

    cout << max_num << endl;
}
