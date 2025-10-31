#include <bits/stdc++.h>
using namespace std;

struct Edge { int u, v, w; };
int main() {
    int n, m; cin >> n >> m;
    vector<Edge> edges(m);
    for(int i=0;i<m;i++) cin >> edges[i].u >> edges[i].v >> edges[i].w;

    int s; cin >> s;
    vector<long long> dist(n, LLONG_MAX);
    dist[s] = 0;

    for(int i=0;i<n-1;i++) {
        for(auto e: edges) {
            if(dist[e.u] != LLONG_MAX && dist[e.u] + e.w < dist[e.v])
                dist[e.v] = dist[e.u] + e.w;
        }
    }

    // Check negative cycle
    bool neg_cycle = false;
    for(auto e: edges) {
        if(dist[e.u] != LLONG_MAX && dist[e.u] + e.w < dist[e.v]) {
            neg_cycle = true;
            break;
        }
    }

    if(neg_cycle) cout << "Negative weight cycle detected!\n";
    else for(int i=0;i<n;i++)
        cout << "Distance from " << s << " to " << i << ": " << dist[i] << "\n";
}
