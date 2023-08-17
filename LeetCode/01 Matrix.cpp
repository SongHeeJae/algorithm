/*
값이 0인 좌표를 모두 큐에 담아주고, BFS를 수행하면 됩니다.
*/

class Solution {
public:
    int d[5] = {0,-1,0,1,0};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat.front().size();

        queue<pair<int, int>> q;
        vector<vector<int>> dist(n, vector<int>(m, -1));
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j] == 0) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(int i=0; i<4; i++) {
                int nx = x + d[i];
                int ny = y + d[i + 1];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if(dist[nx][ny] != -1) continue;
                q.push({nx, ny});
                dist[nx][ny] = dist[x][y] + 1;
            }
        }

        return dist;
    }
};
