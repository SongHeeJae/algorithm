/*
다익스트라 알고리즘을 이용하여 풀 수 있었습니다.
*/

class Solution {
public:
    int d[5] = {0,-1,0,1,0};
   
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights.front().size();
        int eff[100][100];
        memset(eff, 0x07, sizeof(eff));
       
        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({0, {0, 0}});
        
        eff[0][0] = 0;
        while(!pq.empty()) {
            int c = -pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            
            if(x == n - 1 && y == m - 1) break;
            if(eff[x][y] < c) continue;
            
            for(int i=0; i<4; i++) {
                int nx = x + d[i];
                int ny = y + d[i + 1];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                int nc = max(eff[x][y], abs(heights[x][y] - heights[nx][ny]));
                if(eff[nx][ny] > nc) {
                    eff[nx][ny] = nc;
                    pq.push({-nc, {nx, ny}});
                }
            }
        }
        return eff[n - 1][m - 1];
    }
};