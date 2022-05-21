/*
dp를 이용하여 풀 수 있었습니다.
dp[i][j] = (i, j)에서 증가하는 경로의 가장 큰 길이를 기억해줍니다.
모든 정점에서 dfs를 수행하면서 다음 정점에 이미 더 큰 길이가 저장되어있다면, 해당 경로는 방문할 필요가 없습니다.
그렇지 않다면, 다음 정점을 방문하여 dp를 업데이트해줍니다.
dp에 저장된 값 중 가장 큰 값을 반환해주면 됩니다.
*/

class Solution {
public:
    int d[5] = {0,-1,0,1,0};
    int dp[200][200] = {0};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        for(int i=0; i<matrix.size(); i++)
            for(int j=0; j<matrix.front().size(); j++)
                dfs(matrix, i, j, 0);
        
        int res = INT_MIN;
        for(int i=0; i<matrix.size(); i++)
            for(int j=0; j<matrix.front().size(); j++)
                res = max(res, dp[i][j]);
        return res + 1;
    }
    
    void dfs(vector<vector<int>>& matrix, int x, int y, int depth) {
        dp[x][y] = max(dp[x][y], depth);
        for(int i=0; i<4; i++) {
            int nx = x + d[i];
            int ny = y + d[i + 1];
            if(nx < 0 || ny < 0 || nx >= matrix.size() || ny >= matrix.front().size()) continue;
            if(matrix[x][y] >= matrix[nx][ny]) continue;
            if(dp[x][y] < dp[nx][ny]) continue;
            dfs(matrix, nx, ny, depth + 1);
        }
    }
};