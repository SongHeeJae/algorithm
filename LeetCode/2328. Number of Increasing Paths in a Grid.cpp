/*
DFS를 수행하며 각 셀에서 나올 수 있는 모든 경로의 수를 기억해줍니다.
*/

class Solution {
public:
    const int MOD = 1e9 + 7;

    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    int visit[1000][1000] = {0};

    int countPaths(vector<vector<int>>& grid) {
        int c = 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                c += dfs(grid, i, j);
                c %= MOD;
            }
        }
        return c;
    }

    int dfs(vector<vector<int>>& grid, int x, int y) {
        if(visit[x][y]) {
            return visit[x][y];
        }

        visit[x][y] = 1;
        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size() || grid[x][y] >= grid[nx][ny]) continue;
            visit[x][y] += dfs(grid, nx, ny);
            visit[x][y] %= MOD;
        }

        return visit[x][y];
    }
};
