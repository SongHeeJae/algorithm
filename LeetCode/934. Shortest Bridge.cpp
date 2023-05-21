/*
첫번째 섬과 인접한 물의 좌표와, 두번째 섬과 인접한 물의 좌표를 구해줍니다.
구해진 좌표를 이용하여 두 섬 사이의 최단 거리를 구해줍니다.
*/

class Solution {
public:
    int d[5] = {0,-1,0,1,0};
    bool visit[100][100] = {false};
    vector<pair<int, int>> first, second;
    int shortestBridge(vector<vector<int>>& grid) {
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid.size(); j++) {
                if(grid[i][j]) {
                    dfs(grid, i, j, first.empty()? first : second);
                }
            }
        }

        int res = INT_MAX;
        for(auto& f : first) {
            for(auto& s : second) {
                int dist = abs(f.first - s.first) + abs(f.second - s.second) + 1;
                res = min(res, dist);
            }
        }
        return res;
    }
    
    void dfs(vector<vector<int>>& grid, int x, int y, vector<pair<int, int>>& arr) {
        if(!grid[x][y]) {
            arr.push_back({x, y});
            return;
        }
        if(visit[x][y]) return;
        visit[x][y] = true;
        for(int i=0; i<4; i++) {
            int nx = x + d[i];
            int ny = y + d[i + 1];
            if(nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid.size()) continue;
            dfs(grid, nx, ny, arr);
        }
    }
};


/*
첫번째 섬과 인접한 물의 좌표를 구해줍니다.
해당 좌표에서부터 두번째 섬을 찾을 때 까지 BFS를 수행해줍니다.
*/

class Solution {
public:
    int d[5] = {0,-1,0,1,0};
    int visit[100][100] = {0};
    queue<pair<int, int>> q;
    int shortestBridge(vector<vector<int>>& grid) {
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid.size(); j++) {
                if(grid[i][j] && q.empty()) {
                    dfs(grid, i, j);
                }
            }
        }

        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(grid[x][y]) return visit[x][y] - 1;
            for(int i=0; i<4; i++) {
                int nx = x + d[i];
                int ny = y + d[i + 1];
                if(nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid.size()|| visit[nx][ny]) continue;
                q.push({nx, ny});
                visit[nx][ny] = visit[x][y] + 1;  
            }
        }
        return -1;
    }
    
    void dfs(vector<vector<int>>& grid, int x, int y) {
        if(!grid[x][y]) {
            q.push({x, y});
            visit[x][y] = 1;
            return;
        }
        if(visit[x][y]) return;
        visit[x][y] = 1;
        for(int i=0; i<4; i++) {
            int nx = x + d[i];
            int ny = y + d[i + 1];
            if(nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid.size()) continue;
            dfs(grid, nx, ny);
        }
    }
};
