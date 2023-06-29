/*
BFS와 비트마스킹을 이용하여 풀 수 있었습니다.
각 지점에서 열쇠 획득 여부에 따라 방문을 표시해줍니다.
열쇠 획득 여부는, 6개의 열쇠를 나타내기 위해 6비트로 나타낼 수 있습니다. 각 비트는 열쇠 a,b,c,d,e,f의 획득 여부를 나타냅니다.
*/

class Solution {
public:
    int d[5] = {0,-1,0,1,0};

    int shortestPathAllKeys(vector<string>& grid) {
        bool visit[30][30][1 << 6] = {false};
        int n = grid.size();
        int m = grid.front().size();

        queue<pair<pair<int, int>, int>> q;
        int keySize = 0;
        for(int i=0; i < n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == '@') {
                    q.push({{i, j}, 0});
                    visit[i][j][0] = true;
                    grid[i][j] = '.';
                } else if('a' <= grid[i][j] && grid[i][j] <= 'f') {
                    keySize++;
                }
            }
        }

        int cnt = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int x = q.front().first.first;
                int y = q.front().first.second;
                int k = q.front().second;
                q.pop();
                if (k == (1 << keySize) - 1) return cnt;
                for(int i=0; i<4; i++) {
                    int nx = x + d[i];
                    int ny = y + d[i + 1];
                    int nk = k;
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                    char c = grid[nx][ny];
                    if(c == '#') continue;
                    else if('a' <= c && c <= 'f') nk |= 1 << (c - 'a');
                    else if('A' <= c && c <= 'F' && !((k >> (c - 'A')) & 1)) continue;
                    if(visit[nx][ny][nk]) continue;
                    visit[nx][ny][nk] = true;
                    q.push({{nx, ny}, nk});
                }
            }
            cnt++;
        }
        
        return -1;
    }
};
