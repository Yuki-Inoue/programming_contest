#include <cstdio>
#include <vector>
#include <algorithm>

std::vector<int> g[500];
int matchFrom[500];
std::vector<bool> visited;

bool augment(int u) {
    if (u<0)
        return true;
    for (int i=0; i<g[u].size(); ++i)
        if (!visited[g[u][i]]) {
            visited[g[u][i]] = true;
            if (augment(matchFrom[g[u][i]])) {
                matchFrom[g[u][i]] = u;
                return true;
            }
        }
    return false;
}

int main(){
    int N, K;
    scanf(" %d %d", &N, &K);
    for (int i=0; i<K; ++i) {
        int R, C;
        scanf(" %d %d", &R, &C);
        R--; C--;
        g[R].push_back(C);
    }
    std::fill(matchFrom, matchFrom+N, -1);

    int match = 0;
    for (int u=0; u<N; ++u) {
        visited.clear();
        visited.resize(N);
        if (augment(u))
            match++;
    }

    printf("%d\n", match);
}
