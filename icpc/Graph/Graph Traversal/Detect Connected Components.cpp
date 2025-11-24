int countComponents(const vector<vector<int>> &adj) {
    int n = adj.size();
    vector<bool> visited(n,false);
    int count = 0;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            count++;
            DFS(i, adj, visited);
        }
    }
    return count;
}
