#include <bits/stdc++.h>
using namespace std;

void DFS(int u, const vector<vector<int>> &adj, vector<bool> &visited) {
    visited[u] = true;
    cout << u << " "; // process node
    for(int v: adj[u])
        if(!visited[v]) DFS(v, adj, visited);
}

int main() {
    int n,m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // comment if directed
    }

    vector<bool> visited(n,false);
    for(int i=0;i<n;i++)
        if(!visited[i]){
            cout << "Component: ";
            DFS(i, adj, visited);
            cout << "\n";
        }
}
