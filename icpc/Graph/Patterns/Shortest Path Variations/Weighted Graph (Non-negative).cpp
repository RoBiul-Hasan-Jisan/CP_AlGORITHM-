vector<long long> dijkstra(int s, vector<vector<pair<int,int>>> &adj){
    int n = adj.size();
    vector<long long> dist(n, LLONG_MAX); dist[s]=0;
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
    pq.push({0,s});
    while(!pq.empty()){
        auto [d,u]=pq.top(); pq.pop();
        if(d>dist[u]) continue;
        for(auto [v,w]: adj[u]) if(dist[u]+w<dist[v]){
            dist[v]=dist[u]+w; pq.push({dist[v],v});
        }
    }
    return dist;
}
