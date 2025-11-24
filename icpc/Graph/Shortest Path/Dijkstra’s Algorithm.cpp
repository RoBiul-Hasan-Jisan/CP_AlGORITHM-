#include <bits/stdc++.h>
using namespace std;

struct Edge { int to, w; };
int main() {
    int n, m; cin >> n >> m;
    vector<vector<Edge>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        // adj[v].push_back({u, w}); // for undirected
    }

    int s; cin >> s; 
    vector<long long> dist(n, LLONG_MAX);
    dist[s] = 0;
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
    pq.push({0, s});

    while(!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if(d != dist[u]) continue;
        for(auto &e : adj[u]) {
            int v = e.to; long long w = e.w;
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    for(int i=0;i<n;i++)
        cout << "Distance from " << s << " to " << i << ": " << dist[i] << "\n";
}
//Single-source shortest path.

//Works only for non-negative edge weights.

//Uses priority queue (min-heap).