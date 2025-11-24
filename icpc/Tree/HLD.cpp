int chainHead[MAXN], chainInd[MAXN], posInBase[MAXN];
int baseArray[MAXN], ptr = 0;
int chainNo = 0;

void HLD(int u, int p){
    if(chainHead[chainNo] == -1) chainHead[chainNo] = u;
    chainInd[u] = chainNo;
    posInBase[u] = ptr;
    baseArray[ptr++] = u;

    int mx = -1, heavyChild = -1;
    for(int v: adj[u]){
        if(v == p) continue;
        if(subtree_size[v] > mx){
            mx = subtree_size[v];
            heavyChild = v;
        }
    }

    if(heavyChild != -1) HLD(heavyChild, u);

    for(int v: adj[u]){
        if(v==p || v==heavyChild) continue;
        chainNo++;
        HLD(v,u);
    }
}
