class Solution {
public:
    int dp[70][70][70];

    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        return cherryPickup(grid, 0, 0, grid[0].size() - 1);
    }

    int cherryPickup(vector<vector<int>>& grid, int x, int y1, int y2) {
        if(x == grid.size()) {
            return 0;
        }

        if(y1 < 0 || y1 >= grid[0].size() || y2 < 0 || y2 >= grid[0].size()) {
            return 0;
        }

        if(y1 == y2) {
            return 0;
        }

        if(dp[x][y1][y2] != -1) return dp[x][y1][y2];

        return dp[x][y1][y2] = max({
            cherryPickup(grid, x + 1, y1 - 1, y2 - 1),
            cherryPickup(grid, x + 1, y1 - 1, y2),
            cherryPickup(grid, x + 1, y1 - 1, y2 + 1),
            cherryPickup(grid, x + 1, y1, y2 - 1),
            cherryPickup(grid, x + 1, y1, y2),
            cherryPickup(grid, x + 1, y1, y2 + 1),
            cherryPickup(grid, x + 1, y1 + 1, y2 - 1),
            cherryPickup(grid, x + 1, y1 + 1, y2),
            cherryPickup(grid, x + 1, y1 + 1, y2 + 1)
        }) + grid[x][y1] + grid[x][y2];
    }
};
