#include <iostream>
#include <vector>
#include <climits>


struct Edge {
    int from, to;
    long cost;
    explicit Edge(int f, int t, long c)
    : from(f), to(t), cost(c) {}
};


typedef std::vector<Edge> Edges;



int main(){
    int N, ML, MD;
    std::cin >> N >> ML >> MD;

    Edges edges;
    {
        for (int i=1; i<N; ++i)
            edges.push_back(Edge(i+1,i,0));
        while (ML--) {
            int A,B;
            long D;
            std::cin >> A >> B >> D;
            edges.push_back(Edge(A,B,D));
        }
        while (MD--) {
            int A,B;
            long D;
            std::cin >> A >> B >> D;
            edges.push_back(Edge(B,A,-D));
        }
    }

    std::vector<long> distance1(N+1,LONG_MAX);
    distance1[1] = 0;
    {
        bool update;
        int count = 0;
        do {
            ++count;
            update = false;
            for (int i=0; i<edges.size(); ++i) {
                const Edge &e = edges[i];
                if (distance1[e.from] != LONG_MAX &&
                    distance1[e.from] + e.cost < distance1[e.to]) {
                    update = true;
                    distance1[e.to] = distance1[e.from] + e.cost;
                }
            }
        } while (update && count < edges.size());

        std::cout <<
        (count == edges.size() ? -1 :
         distance1[N] == LONG_MAX ? -2 : distance1[N]) << std::endl;
    }

}
