#include <bits/stdc++.h>
using namespace std;

void BFS(int s, const vector<vector<int>> &adj, vector<int> &dist) {
    int n = adj.size();
    dist.assign(n, -1); // -1 = unvisited
    queue<int> q;
    dist[s] = 0;
    q.push(s);

    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v: adj[u]) {
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // comment if directed
    }

    vector<int> dist;
    BFS(0, adj, dist);
    for(int i=0;i<n;i++)
        cout << "Distance from 0 to " << i << ": " << dist[i] << "\n";
}
