#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> in_deg;

int main() {
    int n, m; cin >> n >> m;
    adj.assign(n, {});
    in_deg.assign(n, 0);
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        in_deg[v]++;
    }

    queue<int> q;
    for(int i = 0; i < n; i++) if(in_deg[i] == 0) q.push(i);

    vector<int> topo;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for(int v: adj[u])
            if(--in_deg[v] == 0) q.push(v);
    }

    for(int x: topo) cout << x << " ";
}
