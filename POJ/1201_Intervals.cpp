#include <iostream>
#include <vector>

using namespace std;

struct Edge { int from, to, cost; };

int main(){
    int n;
    cin >> n;

    vector<Edge> edges(50001*2+n);
    for (int i=0; i<50001; ++i) {
        edges[2*i].from = i;
        edges[2*i].to   = i+1;
        edges[2*i].cost = 1;
        edges[2*i+1].from = i+1;
        edges[2*i+1].to   = i;
        edges[2*i+1].cost = 0;
    }

    for (int i=0; i<n; ++i) {
        int ai,bi,ci;
        cin >> ai >> bi >> ci;
        edges[50001*2+i].from = bi+1;
        edges[50001*2+i].to   = ai;
        edges[50001*2+i].cost = -ci;
    }



    vector<int> distance(50002,0);
    while (true) {
        bool updated = false;
        for (int i=0; i<edges.size(); ++i)
            if (edges[i].cost + distance[edges[i].from] < distance[edges[i].to]) {
                updated = true;
                distance[edges[i].to] = distance[edges[i].from] + edges[i].cost;
            }
        if (!updated) break;
    }

    cout << -distance[0] << endl;
}
