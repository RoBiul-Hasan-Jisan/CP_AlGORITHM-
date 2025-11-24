int n;
vector<vector<int>> adj;
vector<vector<int>> dp; // dp[mask][u] = true if path ends at u using mask

bool hamiltonian(){
    dp.assign(1<<n, vector<int>(n,0));
    for(int i=0;i<n;i++) dp[1<<i][i]=1;
    for(int mask=1; mask<(1<<n); mask++){
        for(int u=0; u<n; u++){
            if(!(mask&(1<<u))) continue;
            for(int v: adj[u]){
                if(mask&(1<<v)) continue;
                dp[mask|(1<<v)][v] |= dp[mask][u];
            }
        }
    }
    for(int i=0;i<n;i++) if(dp[(1<<n)-1][i]) return true;
    return false;
}
