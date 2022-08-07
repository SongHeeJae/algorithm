/*
DFS와 DP를 이용하여 풀 수 있었습니다.

dp[i][j][k] = (i, j)에서 k만큼 남았을 때의 경계를 벗어날 수 있는 경우의 수를 저장해줍니다.

dp[i][j][k] = dp[i - 1][j][k - 1] + dp[i][j - 1][k - 1] + dp[i + 1][j][k - 1] + dp[i][j + 1][k - 1]이 됩니다.

이동 횟수가 남아있으면서 경계를 벗어날 때마다 경우의 수 1을 반환해줍니다.
*/

class Solution {
public:
    int MOD = 1000000007;
    
    int d[5] = {0,-1,0,1,0};
    int dp[50][50][51];
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        return dfs(m, n, maxMove, startRow, startColumn);
    }
           
    int dfs(int m, int n, int move, int x, int y) {
        if(move < 0) 
            return 0;
        
        if(x < 0 || y < 0 || x >= m || y >= n) 
            return 1;
        
        if(dp[x][y][move] != -1) 
            return dp[x][y][move];
        
        dp[x][y][move] = 0;
        for(int i=0; i<4; i++) {
            int nx = x + d[i];
            int ny = y + d[i + 1];
            dp[x][y][move] += dfs(m, n, move - 1, nx , ny);
            dp[x][y][move] %= MOD;
        }
        return dp[x][y][move];
    }
    
};
