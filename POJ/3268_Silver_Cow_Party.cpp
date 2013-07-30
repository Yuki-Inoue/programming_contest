#include <vector>
#include <climits>
#include <queue>
#include <functional>

struct Edge {
    int to, time;
    Edge (int to_, int time_) : to(to_), time(time_) {}
};

typedef std::vector<Edge> Adjacency;

Adjacency graph[1000];
Adjacency rev_graph[1000];

typedef std::pair<int, int> QueueEntry;

void dijkstra(int s, int N, int *d, const Adjacency g[]) {
    for (int i=0; i<N; ++i)
        d[i] = INT_MAX;
    std::priority_queue<QueueEntry, std::vector<QueueEntry>, std::greater<QueueEntry> > pqueue;
    pqueue.push(std::make_pair(0, s));
    while (!pqueue.empty()) {
        int d_cand = pqueue.top().first;
        int v = pqueue.top().second;
        pqueue.pop();
        if (d_cand >= d[v]) continue;
        d[v] = d_cand;
        for (int i=0; i< g[v].size(); ++i)
            pqueue.push(std::make_pair(d[v] + g[v][i].time, g[v][i].to));
    }
}

int main(){
    int N,M,X;
    scanf(" %d %d %d", &N, &M, &X);
    X--;
    int d[1000];
    int rev_d[1000];
    for (int i=0; i<M; ++i) {
        int Ai, Bi, Ti;
        scanf(" %d %d %d", &Ai, &Bi, &Ti);
        Ai--; Bi--;
        graph[Ai].push_back(Edge(Bi, Ti));
        rev_graph[Bi].push_back(Edge(Ai,Ti));
    }
    dijkstra(X, N, d, graph);
    dijkstra(X, N, rev_d, rev_graph);

    int max_d = INT_MIN;

    for (int i=0; i<N; ++i)
        max_d = std::max(d[i]+rev_d[i], max_d);

    printf("%d\n", max_d);
}
