/*
grid 범위를 벗어날 수 없는, 고립된 영역의 land cell 개수를 구해주었습니다.
*/

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int cnt = 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[i].size(); j++) {
                if(grid[i][j]) {
                    int ret = dfs(grid, i, j);
                    if(ret > 0) cnt += ret;
                }
            }
        }
        return cnt;
    }

    int dfs(vector<vector<int>>& grid, int x, int y) {
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()) return -2500000;
    
        if(!grid[x][y]) {
            return 0;
        }

        grid[x][y] = 0;

        return dfs(grid, x + 1, y)
            + dfs(grid, x - 1, y)
            + dfs(grid, x, y + 1)
            + dfs(grid, x, y - 1)
            + 1;
    }
};
