/*

Start from any node.

Always add the minimum weight edge that connects a visited node to an unvisited node.

Use priority queue (min-heap) for efficiency.

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<m;i++){
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<bool> visited(n,false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,0}); // {weight, node}
    long long mst_weight = 0;

    while(!pq.empty()){
        auto [w,u] = pq.top(); pq.pop();
        if(visited[u]) continue;
        visited[u]=true;
        mst_weight += w;
        for(auto [v,wt]: adj[u]){
            if(!visited[v]) pq.push({wt,v});
        }
    }

    cout << "MST Weight: " << mst_weight << "\n";
    return 0;
}
