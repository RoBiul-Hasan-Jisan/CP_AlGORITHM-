bool dfsCycle(int u, vector<vector<int>> &adj, vector<int> &vis){
    vis[u] = 1;
    for(int v: adj[u]){
        if(vis[v]==1) return true; // back-edge
        if(vis[v]==0 && dfsCycle(v,adj,vis)) return true;
    }
    vis[u]=2;
    return false;
}
