#include <bits/stdc++.h>
using namespace std;



vector<int>bfsofG(int v,vector<vector<int>>&adj)
{
  vector<int>bfs;
  vector<int>visit(v,false);
  queue<int>q;

  q.push(0);
  visit[0]=true;


  while(!q.empty())
  {
    int node = q.front();
    q.pop();
    bfs.push_back(node) ;

    for(int i : adj[node])
    {
      if(!visit[i])
      {
        visit[i]=true;
        q.push(i);

      }
    }

  }
  return bfs;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
  int v,e;
  cin>>v>>e;
  vector<vector<int>>adj(v);
  for(int i = 0; i < e; i++){

     int u,V;  cin>>u>>V;
     adj[u].push_back(V);
     adj[V].push_back(u);



  }

  vector<int>ans=bfsofG(v,adj);
  for(int x : ans)
  {
    cout<<x<<" ";

  }
  cout<<endl;

}
