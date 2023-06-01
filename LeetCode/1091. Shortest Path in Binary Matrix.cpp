/*
BFS를 수행하여 거리를 구해줍니다.
*/

class Solution {
public:
    int dx[8] = {-1,0,1,0,-1,-1,1,1};
    int dy[8] = {0,-1,0,1,-1,1,-1,1};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] || grid[n - 1][n - 1]) return -1;

        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;

        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if(x == n - 1 && y == n - 1) {
                return grid[x][y];
            }

            for(int i=0; i<8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || ny < 0 || nx >= n || ny >= n || grid[nx][ny]) continue;
                grid[nx][ny] = grid[x][y] + 1;
                q.push({nx, ny}); 
            }
        }

        return -1;
    }
};
