#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;
vector<int> adj[MAXN];
int parent[MAXN], depth[MAXN], subtree_size[MAXN];

// calculates parent, depth, and subtree sizes
void dfs(int u, int p){
    parent[u] = p;
    subtree_size[u] = 1; // include self
    for(int v : adj[u]){
        if(v == p) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
        subtree_size[u] += subtree_size[v];
    }
}

int main(){
    int n; cin >> n;
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    depth[1] = 0; // assuming 1 is root
    dfs(1,1);

    for(int i=1;i<=n;i++)
        cout << "Node " << i << ": depth=" << depth[i] << ", parent=" << parent[i]
             << ", subtree_size=" << subtree_size[i] << "\n";

    return 0;
}
