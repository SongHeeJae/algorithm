/*
아직 방문하지 않은 land cell에 도달할 때마다 DFS를 수행하여, 섬에 속한 모든 land cell에 방문 표시를 해줍니다.
*/

class Solution {
public:
    bool v[300][300] = {false};
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(!v[i][j] && grid[i][j] == '1') {
                    dfs(grid, i, j);
                    res++;
                }
            }
        }
        return res;
    }
    
    void dfs(vector<vector<char>>& grid, int x, int y) {
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()) return;
        if(v[x][y] || grid[x][y] != '1') return;
        v[x][y] = true;
        dfs(grid, x + 1, y);
        dfs(grid, x - 1, y);
        dfs(grid, x, y - 1);
        dfs(grid, x, y + 1);
    }
};

