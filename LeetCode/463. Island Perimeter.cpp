/*
land cell을 찾은 지점부터 dfs를 수행해줍니다. land 범위 벗어나거나 water cell이라면 1의 길이를 더해줍니다.
*/

class Solution {
public:
    bool visit[100][100] = {false};

    int islandPerimeter(vector<vector<int>>& grid) {
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    return dfs(grid, i, j);
                }
            }
        }
        return 0;
    }

private:
    int dfs(vector<vector<int>>& grid, int x, int y) {
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || !grid[x][y]) {
            return 1;
        }

        if(visit[x][y]) {
            return 0;
        }

        visit[x][y] = true;

        return dfs(grid, x + 1, y)
            + dfs(grid, x - 1, y)
            + dfs(grid, x, y + 1)
            + dfs(grid, x, y - 1);
    }
};

/*
grid를 순회하면서 land cell이라면 사방향을 검사해줄 수도 있습니다.
*/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(!grid[i][j]) continue;
                res += i == 0 || !grid[i - 1][j];
                res += i == grid.size() - 1 || !grid[i + 1][j];
                res += j == 0 || !grid[i][j - 1];
                res += j == grid[0].size() - 1 || !grid[i][j + 1];
            }
        }
        return res;
    }
};
