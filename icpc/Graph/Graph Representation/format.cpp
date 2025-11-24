#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false); cin.tie(nullptr);




struct GraphMatrix {
    int n;
    vector<vector<int>> adj;

    GraphMatrix(int n) {
        this->n = n;
        adj.assign(n, vector<int>(n, 0)); // 0 = no edge, jodi  lage use INF for weights
    }

    void addEdge(int u, int v, int w=1, bool directed=false) {
        adj[u][v] = w;
        if(!directed) adj[v][u] = w;
    }

    void print() {
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) cout << adj[i][j] << " ";
            cout << "\n";
        }
    }
};


struct GraphList {
    int n;
    vector<vector<int>> adj;         // unweighted
    vector<vector<pair<int,int>>> adjW; // weighted

    GraphList(int n) {
        this->n = n;
        adj.assign(n, vector<int>());
        adjW.assign(n, vector<pair<int,int>>());
    }

    void addEdge(int u, int v, bool directed=false) {
        adj[u].push_back(v);
        if(!directed) adj[v].push_back(u);
    }

    void addEdgeWeighted(int u, int v, int w, bool directed=false) {
        adjW[u].push_back({v,w});
        if(!directed) adjW[v].push_back({u,w});
    }

    void print() {
        for(int i=0;i<n;i++){
            cout << i << ": ";
            for(int v: adj[i]) cout << v << " ";
            cout << "\n";
        }
    }

    void printWeighted() {
        for(int i=0;i<n;i++){
            cout << i << ": ";
            for(auto &p: adjW[i]) cout << "(" << p.first << "," << p.second << ") ";
            cout << "\n";
        }
    }
};

struct Edge { int u, v, w; };


int main() {
    fast;
    int n, m;
    cin >> n >> m; // nodes and edges

    // 1️⃣ Matrix
    GraphMatrix gm(n);

    // 2️⃣ List
    GraphList gl(n);

    // 3️⃣ Edge List
    vector<Edge> edges;

    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w; // weighted edge input
        // fill all representations
        gm.addEdge(u,v,w,false);        // undirected weighted
        gl.addEdgeWeighted(u,v,w,false);
        gl.addEdge(u,v,false);          // unweighted
        edges.push_back({u,v,w});
    }

    cout << "Adjacency Matrix:\n"; gm.print();
    cout << "\nAdjacency List:\n"; gl.print();
    cout << "\nWeighted Adjacency List:\n"; gl.printWeighted();

    cout << "\nEdge List:\n";
    for(auto e: edges) cout << e.u << " " << e.v << " " << e.w << "\n";

    return 0;
}
