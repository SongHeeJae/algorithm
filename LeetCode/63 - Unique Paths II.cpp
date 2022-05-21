/*
dp를 이용하여 풀 수 있었습니다.
이미 방문한 적 있는 경로라면,
지금 방문하는 경로에서 갈 수 있는 경우의 수는, 해당 경로에서 갈 수 있었던 경우의 수 만큼 늘어납니다.
*/

class Solution {
public:
    int d[3] = {0,1,0};
    int dp[100][100] = {0};
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        return dfs(obstacleGrid, 0, 0);
    }
    
    int dfs(vector<vector<int>>& obstacleGrid, int x, int y) {
        if(x == obstacleGrid.size() - 1 && y == obstacleGrid.front().size() - 1) return !obstacleGrid[x][y];
        if(obstacleGrid[x][y]) return 0;
        if(dp[x][y]) return dp[x][y];
        
        for(int i=0;i<2; i++) {
            int nx = x + d[i];
            int ny = y + d[i + 1];
            if(nx < 0 || ny < 0 || nx >= obstacleGrid.size() || ny >= obstacleGrid.front().size()) continue;
            dp[x][y] += dfs(obstacleGrid, nx, ny);
        }
        return dp[x][y];
    }
};


/*
다음과 같이 반복문을 이용하여 풀 수도 있었습니다.
위에서 넘어왔을 때와 왼쪽에서 넘어왔을 때의 경로의 수를 업데이트해줍니다.
*/
class Solution {
public:
    int dp[101][101] = {0};
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        dp[0][1] = 1;
        for(int i=1; i<=obstacleGrid.size(); i++) {
            for(int j=1; j<=obstacleGrid.front().size(); j++) {
                if(obstacleGrid[i-1][j-1]) continue;
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[obstacleGrid.size()][obstacleGrid.front().size()];
    }
};