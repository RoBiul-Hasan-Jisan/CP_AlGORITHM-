bool dfsCycleUndirected(int u, int parent, const vector<vector<int>> &adj, vector<bool> &visited) {
    visited[u] = true;
    for(int v: adj[u]){
        if(!visited[v]){
            if(dfsCycleUndirected(v,u,adj,visited)) return true;
        }
        else if(v != parent) return true; // back edge
    }
    return false;
}

bool hasCycleUndirected(const vector<vector<int>> &adj){
    int n = adj.size();
    vector<bool> visited(n,false);
    for(int i=0;i<n;i++)
        if(!visited[i] && dfsCycleUndirected(i,-1,adj,visited)) return true;
    return false;
}
//Use DFS with parent tracking.

bool dfsCycleDirected(int u, const vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &recStack) {
    visited[u] = true;
    recStack[u] = true;
    for(int v: adj[u]){
        if(!visited[v] && dfsCycleDirected(v, adj, visited, recStack)) return true;
        else if(recStack[v]) return true; // back edge
    }
    recStack[u] = false;
    return false;
}

bool hasCycleDirected(const vector<vector<int>> &adj){
    int n = adj.size();
    vector<bool> visited(n,false), recStack(n,false);
    for(int i=0;i<n;i++)
        if(!visited[i] && dfsCycleDirected(i,adj,visited,recStack)) return true;
    return false;
}
//Use DFS with recursion stack.