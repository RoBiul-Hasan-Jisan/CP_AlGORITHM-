vector<int> bfs(int s, vector<vector<int>> &adj) {
    int n = adj.size();
    vector<int> dist(n, -1); dist[s] = 0;
    queue<int> q; q.push(s);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v: adj[u]) if(dist[v] == -1){
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
    return dist;
}
