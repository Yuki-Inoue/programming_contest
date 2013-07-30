#include <iostream>
#include <vector>
#include <algorithm>

struct Edge {
    int to, weight;
    Edge(int to_, int w_) : to(to_), weight(w_){}
};

int main(){
    int n,m,p,a,b;
    while (std::cin >> n >> m >> p >> a >> b && n) {
        --a; --b;

        int tickets[8];
        for (int i=0; i<n; ++i)
            std::cin >> tickets[i];

        std::vector<Edge> graph[30];
        for (int i=0; i<p; ++i) {
            int xi, yi, zi;
            std::cin >> xi >> yi >> zi;
            xi--; yi--;
            graph[xi].push_back(Edge(yi, zi));
            graph[yi].push_back(Edge(xi, zi));
        }

        const double DISTANCE_MAX = 3000.0;
        double dp[1 << 8][30];
        for (int i=0; i< 1<<n; ++i)
            for (int j=0; j<m; ++j)
                dp[i][j] = DISTANCE_MAX;

        for (int i=0; i< 1<<n; ++i)
            dp[i][a] = 0.0;

        for (int i=0; i< 1<<n; ++i)
            for (int j=0; j<m; ++j)
                for (int k=0; k<graph[j].size(); ++k)
                    for (int t=0; t<n; ++t) {
                        int newset = i|(1<<t);
                        if (newset != i) {
                            int dst = graph[j][k].to;
                            dp[newset][dst] =
                            std::min(dp[newset][dst],
                                     dp[i][j] + (double)graph[j][k].weight / tickets[t]);
                        }
                    }


        double min_d = DISTANCE_MAX;
        for (int i=0; i< 1<<n; ++i)
            min_d = std::min(min_d, dp[i][b]);

        if (min_d == DISTANCE_MAX) {
            std::cout << "Impossible" << std::endl;
        }
        else {
            std::cout << min_d << std::endl;
        }
    }
}
