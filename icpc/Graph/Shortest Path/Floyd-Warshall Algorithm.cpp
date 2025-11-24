//All-Pairs Shortest Path
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    const long long INF = 1e18;
    vector<vector<long long>> dist(n, vector<long long>(n, INF));
    for(int i=0;i<n;i++) dist[i][i] = 0;

    for(int i=0;i<m;i++) {
        int u,v,w; cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], (long long)w);
        // dist[v][u] = min(dist[v][u], (long long)w); // undirected
    }

    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(dist[i][k]<INF && dist[k][j]<INF)
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout << (dist[i][j]==INF?"INF":to_string(dist[i][j])) << " ";
        cout << "\n";
    }
}
//Computes shortest paths between every pair of vertices.

//Works with negative weights but no negative cycles.

//Complexity: O(n³)