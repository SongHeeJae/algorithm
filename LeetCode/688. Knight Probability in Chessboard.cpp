/*
8개의 방향으로 이동하므로, 각 이동에서 살아남으면 12.5%의 확률이 올라갑니다.
k번 이동하면서 확률을 구해주고, 각 위치와 이동 횟수에 대한 확률을 기억해줍니다.
*/

class Solution {
public:
    int dx[8] = {-2,-2,-1,-1,1,1,2,2};
    int dy[8] = {-1,1,-2,2,-2,2,-1,1};
    double dp[101][25][25] = {0};

    double knightProbability(int n, int k, int row, int column) {
        return dfs(n, k, row, column);
    }

    double dfs(int n, int k, int x, int y) {
        if(x < 0 || y < 0 || x >= n || y >= n) return 0;
        if(k == 0) return 1;
        if(dp[k][x][y]) return dp[k][x][y];
        for(int i=0; i<8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            dp[k][x][y] += 0.125 * dfs(n, k - 1, nx, ny);
        }
        return dp[k][x][y];
    }
};
