const int LOGN = 20; // 2^20 > 1e5
int up[MAXN][LOGN];

// build binary lifting table
void build_lca(int n){
    for(int i=1;i<=n;i++)
        up[i][0] = parent[i];
    for(int j=1;j<LOGN;j++)
        for(int i=1;i<=n;i++)
            up[i][j] = up[ up[i][j-1] ][j-1];
}

// LCA query
int lca(int u, int v){
    if(depth[u] < depth[v]) swap(u,v);
    int diff = depth[u] - depth[v];
    for(int i=0;i<LOGN;i++)
        if(diff & (1<<i)) u = up[u][i];
    if(u == v) return u;
    for(int i=LOGN-1;i>=0;i--){
        if(up[u][i] != up[v][i]){
            u = up[u][i];
            v = up[v][i];
        }
    }
    return parent[u];
}
