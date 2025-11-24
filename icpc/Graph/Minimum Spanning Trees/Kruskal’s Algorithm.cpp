/*
Sort all edges by weight (smallest to largest).

Pick edges one by one and add to MST if it doesn’t create a cycle.

Use Disjoint Set Union (DSU / Union-Find) to detect cycles efficiently


*/
#include <bits/stdc++.h>
using namespace std;

struct Edge { int u, v, w; };
bool cmp(Edge a, Edge b){ return a.w < b.w; }

struct DSU {
    vector<int> parent, sz;
    DSU(int n){ parent.resize(n); sz.assign(n,1); iota(parent.begin(), parent.end(),0);}
    int find(int x){ return parent[x]==x?x:parent[x]=find(parent[x]); }
    bool unite(int x, int y){
        x=find(x); y=find(y);
        if(x==y) return false;
        if(sz[x]<sz[y]) swap(x,y);
        parent[y]=x; sz[x]+=sz[y]; return true;
    }
};

int main(){
    int n, m; cin >> n >> m; // n = nodes, m = edges
    vector<Edge> edges(m);
    for(int i=0;i<m;i++) cin >> edges[i].u >> edges[i].v >> edges[i].w;

    sort(edges.begin(), edges.end(), cmp);
    DSU dsu(n);
    long long mst_weight = 0;
    vector<Edge> mst_edges;

    for(auto e: edges){
        if(dsu.unite(e.u, e.v)){
            mst_weight += e.w;
            mst_edges.push_back(e);
        }
    }

    cout << "MST Weight: " << mst_weight << "\n";
    return 0;
}
