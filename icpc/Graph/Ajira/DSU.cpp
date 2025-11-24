#include <bits/stdc++.h>
using namespace std;

struct DSU{
    vector<int> parent, sz;
    DSU(int n){parent.resize(n); sz.assign(n,1); iota(parent.begin(),parent.end(),0);}
    int find(int x){return parent[x]==x?x:parent[x]=find(parent[x]);}
    void unite(int a,int b){a=find(a); b=find(b); if(a==b) return; if(sz[a]<sz[b]) swap(a,b); parent[b]=a; sz[a]+=sz[b];}
    bool same(int a,int b){return find(a)==find(b);}
};
