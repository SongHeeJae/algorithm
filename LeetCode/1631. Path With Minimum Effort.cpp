/*
다익스트라 알고리즘을 이용하여 (0, 0)에서 (n-1, m-1)에 도달하기 위한 최소 effort를 구해주었습니다.
*/

class Solution {
public:
    int d[5] = {0,1,0,-1,0}; 
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights.front().size();
        vector<vector<int>> dp(heights.size(), vector<int>(heights.front().size(), INT_MAX));
        priority_queue<pair<int, pair<int, int>>> pq;

        dp[0][0] = 0;
        pq.push({0, {0, 0}});
        while(!pq.empty()) {
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            int e = -pq.top().first;
            pq.pop();

            if(dp[x][y] < e) continue;

            for(int i=0; i < 4; i++) {
                int nx = x + d[i];
                int ny = y + d[i + 1];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m) {
                    continue;
                }

                int ne = max(e, abs(heights[x][y] - heights[nx][ny]));
                
                if(ne < dp[nx][ny]) {
                    pq.push({-ne, {nx, ny}});
                    dp[nx][ny] = ne;
                }
            }
        }

        return dp[n - 1][m - 1];
    }
};
