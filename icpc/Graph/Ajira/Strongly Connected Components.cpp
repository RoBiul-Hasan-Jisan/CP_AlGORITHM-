/*


Detect cycles in directed graphs

Condense graph into DAG

Solve 2-SAT

*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj, radj;
vector<bool> visited;
vector<int> order, component;

void dfs1(int u){
    visited[u] = true;
    for(int v: adj[u]) if(!visited[v]) dfs1(v);
    order.push_back(u);
}

void dfs2(int u){
    visited[u] = true;
    component.push_back(u);
    for(int v: radj[u]) if(!visited[v]) dfs2(v);
}

int main(){
    int n, m; cin >> n >> m;
    adj.assign(n, {}); radj.assign(n, {});
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }

    visited.assign(n,false);
    for(int i=0;i<n;i++) if(!visited[i]) dfs1(i);

    visited.assign(n,false);
    reverse(order.begin(),order.end());
    for(int u: order){
        if(!visited[u]){
            component.clear();
            dfs2(u);
            cout<<"SCC: ";
            for(int x: component) cout<<x<<" ";
            cout<<"\n";
        }
    }
}
