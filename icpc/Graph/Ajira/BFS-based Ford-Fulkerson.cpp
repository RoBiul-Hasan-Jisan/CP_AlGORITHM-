#include <bits/stdc++.h>
using namespace std;

struct Edge{int to, rev; long long cap;};
struct MaxFlow{
    int n; vector<vector<Edge>> g;
    MaxFlow(int n_){n=n_; g.assign(n,{});}
    void add(int u,int v,long long c){
        g[u].push_back({v,(int)g[v].size(),c});
        g[v].push_back({u,(int)g[u].size()-1,0});
    }
    long long bfs(int s,int t,vector<int>& level,vector<int>& iter){
        fill(level.begin(),level.end(),-1); level[s]=0;
        queue<int> q; q.push(s);
        while(!q.empty()){int u=q.front();q.pop();for(auto &e:g[u])if(e.cap>0&&level[e.to]<0){level[e.to]=level[u]+1;q.push(e.to);}}
        return level[t]!=-1;
    }
    long long dfs(int u,int t,long long f,vector<int>& level,vector<int>& iter){
        if(u==t) return f;
        for(;iter[u]<g[u].size();iter[u]++){
            Edge &e=g[u][iter[u]];
            if(e.cap>0&&level[u]<level[e.to]){
                long long d=dfs(e.to,t,min(f,e.cap),level,iter);
                if(d>0){e.cap-=d; g[e.to][e.rev].cap+=d; return d;}
            }
        }
        return 0;
    }
    long long maxFlow(int s,int t){
        long long flow=0;
        vector<int> level(n), iter(n);
        while(bfs(s,t,level,iter)){
            fill(iter.begin(),iter.end(),0);
            long long f;
            while((f=dfs(s,t,LLONG_MAX,level,iter))>0) flow+=f;
        }
        return flow;
    }
};
