#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> tin, low;
vector<bool> visited;
int timer;
vector<pair<int,int>> bridges;

void dfs(int u, int p){
    visited[u] = true;
    tin[u] = low[u] = timer++;
    for(int v: adj[u]){
        if(v == p) continue;
        if(visited[v]) low[u] = min(low[u], tin[v]);
        else{
            dfs(v,u);
            low[u] = min(low[u], low[v]);
            if(low[v] > tin[u]) bridges.push_back({u,v});
        }
    }
}

int main(){
    int n,m; cin>>n>>m;
    adj.assign(n,{});
    for(int i=0;i<m;i++){int u,v;cin>>u>>v;adj[u].push_back(v);adj[v].push_back(u);}
    tin.assign(n, -1); low.assign(n, -1); visited.assign(n,false); timer=0;
    for(int i=0;i<n;i++) if(!visited[i]) dfs(i,-1);
    for(auto p: bridges) cout<<"Bridge: "<<p.first<<" "<<p.second<<"\n";
}
