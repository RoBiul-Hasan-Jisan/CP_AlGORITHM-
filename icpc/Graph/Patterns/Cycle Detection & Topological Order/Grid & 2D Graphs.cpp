vector<int> dx = {0,1,0,-1};
vector<int> dy = {1,0,-1,0};

void dfsGrid(int x, int y, vector<vector<int>> &grid, vector<vector<bool>> &vis){
    int n=grid.size(), m=grid[0].size();
    vis[x][y]=true;
    for(int dir=0; dir<4; dir++){
        int nx = x+dx[dir], ny=y+dy[dir];
        if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && grid[nx][ny]==1)
            dfsGrid(nx, ny, grid, vis);
    }
}
