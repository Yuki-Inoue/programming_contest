#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

inline int pow2(int v){
    return v*v;
}

inline double distance(int x1, int y1, int x2, int y2) {
    return sqrt((double)pow2(x1-x2) + (double)pow2(y1-y2));
}

bool augment(const vector<vector<int> > &graph,
             vector<int> &matchFrom,
             vector<int> &matchTo,
             int u, vector<bool> &visited) {
    if (u<0) {
        return true;
    }
    for (int i=0; i<graph[u].size(); ++i) {
        const int dst = graph[u][i];
        if (visited[dst]) {
            continue;
        }
        visited[dst] = true;
        const int next_u = matchFrom[dst];
        if (augment(graph, matchFrom, matchTo, next_u, visited)) {
            matchFrom[dst] = u;
            matchTo[u] = dst;
            return true;
        }
    }
    return false;
}

int main(){
    int N,M;
    cin >> N >> M;
    vector<int> Nx(N);
    vector<int> Ny(N);
    for (int i=0; i<N; ++i) {
        cin >> Nx[i] >> Ny[i];
    }
    vector<int> Mx(M);
    vector<int> My(M);
    for (int i=0; i<M; ++i) {
        cin >> Mx[i] >> My[i];
    }

    vector<double> edge_length(N-1);
    for (int i=0; i<edge_length.size(); ++i) {
        edge_length[i] = distance(Nx[i],Ny[i], Nx[i+1], Ny[i+1]);
    }

    vector<vector<double> > distances(N);
    for (int i=0; i<N; ++i) {
        vector<double> di(M);
        for (int j=0; j<M; ++j) {
            di[j] = distance(Nx[i],Ny[i], Mx[j], My[j]);
        }
        distances[i].swap(di);
    }

    vector<vector<int> > candidates(N-1);
    for (int i=0; i<N-1; ++i) for (int j=0; j<M; ++j) if (edge_length[i]*2 >= distances[i][j] + distances[i+1][j]) {
        candidates[i].push_back(j);
    }

    vector<int> matchFrom(M,-1);
    vector<int> matchTo(N-1,-1);

    int count = 0;
    for (int i=0; i<N-1; ++i) {
        vector<bool> visited(M,false);
        count += augment(candidates, matchFrom, matchTo, i, visited);
    }

    printf("%d\n%d %d", N+count, Nx[0], Ny[0]);
    for (int i=1; i<N; ++i) {
        const int dog_index
        = matchTo[i-1];
        if (dog_index >= 0)
            printf(" %d %d", Mx[dog_index], My[dog_index]);
        printf(" %d %d", Nx[i], Ny[i]);
    }
    printf("\n");
}
