class Solution {
public:
    int d[5] = {0,1,0,-1,0};
    bool v[50][50] = {false};
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid.front().size();
        int res = 0;
        for(int i=0; i<n; i++) {
            for(int j=0;j<m; j++) {
                if(grid[i][j] && !v[i][j]) 
                    res = max(res, dfs(grid, n, m, i, j));
            }
        }
        return res;
    }
    
    int dfs(vector<vector<int>>& grid, int n, int m, int x, int y) {
        v[x][y] = true;
        int s = 1;
        for(int i=0; i<4; i++) {
            int nx = x + d[i];
            int ny = y + d[i + 1];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m || !grid[nx][ny] || v[nx][ny]) continue;
            s += dfs(grid, n, m, nx, ny);
        }
        return s;
    }
};
