#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <functional>
#include <queue>

using namespace std;

struct E {
    int to, cost;
    explicit E(int t, int c) : to(t), cost(c) {}
};

typedef vector<vector<E> > Graph;


int main(){
    int N; long R;
    cin >> N >> R;
    Graph g(N+1);
    while (R--) {
        int A,B,D;
        cin >> A >> B >> D;
        g[A].push_back(E(B,D));
        g[B].push_back(E(A,D));
    }

    vector<long> min_distance(N+1, LONG_MAX);
    vector<long> second_distance(N+1, LONG_MAX);

    typedef pair<long, int> Entry;
    typedef priority_queue<Entry, vector<Entry>, greater<Entry> > PriorityQueue;

    {
        min_distance[1] = 0;
        PriorityQueue queue;
        queue.push(Entry(0,1));

        while (!queue.empty()) {
            long d = queue.top().first;
            int next = queue.top().second;
            queue.pop();
            if (d > min_distance[next]) continue;
            for (int i=0; i<g[next].size(); ++i) {
                const E &e = g[next][i];
                long d = min_distance[next] + e.cost;
                if (d < min_distance[e.to]){
                    second_distance[e.to] = min_distance[e.to];
                    min_distance[e.to] = d;
                    queue.push(Entry(d,e.to));
                }
                else if (d > min_distance[e.to] && d < second_distance[e.to])
                    second_distance[e.to] = d;
            }
        }
    }

    {
        PriorityQueue queue;
        for (int i=1; i<second_distance.size(); ++i)
            queue.push(Entry(second_distance[i], i));

        while (!queue.empty()) {
            long d = queue.top().first;
            int next = queue.top().second;
            queue.pop();
            if (d > second_distance[next]) continue;

            for (int i=0; i<g[next].size(); ++i) {
                const E &e = g[next][i];
                long d = e.cost + second_distance[next];
                if (d < second_distance[e.to]) {
                    second_distance[e.to] = d;
                    queue.push(Entry(d,e.to));
                }
            }
        }
    }

    cout << second_distance[N] << endl;
}
