/*
DFS로 풀 수 있었습니다.
grid의 land 영역을 탐색하면서, grid의 범위를 벗어날 여지가 있었다면, 사방이 water로 막혀있지 않음을 의미합니다.
dfs 코드를 보면 &&가 아니라 & 연산을 수행하였는데, short circuit evaluation에 의해 앞선 결과가 false라면, 뒤의 연산이 수행되지 않는 상황을 방지하기 위함입니다.
*/

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int cnt = 0;
        for(int i=1; i<grid.size() - 1; i++) {
            for(int j=1; j<grid[i].size() - 1; j++) {
                if(grid[i][j]) continue;
                cnt += dfs(grid, i, j);
            }
        }
        return cnt;
    }

    bool dfs(vector<vector<int>>& grid, int x, int y) {
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()) 
            return false;
        
        if(grid[x][y])
            return true;

        grid[x][y] = 1;

        return dfs(grid, x + 1, y) 
            & dfs(grid, x - 1, y)
            & dfs(grid, x, y + 1)
            & dfs(grid, x, y - 1);
    }
};
