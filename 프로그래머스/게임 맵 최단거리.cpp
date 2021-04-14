#include<vector>
#include <queue>
using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
bool visit[100][100] = {false};

int solution(vector<vector<int> > maps)
{
    int n = maps.size();
    int m = maps[0].size();
    queue<vector<int>> q;
    q.push({ 0, 0, 1});
    visit[0][0] = true;
    while(!q.empty()) {
        int x = q.front()[0];
        int y = q.front()[1];
        int c = q.front()[2];
        q.pop();
        if(x == n - 1 && y == m - 1) {
            return c;
        }
        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(visit[nx][ny] || maps[nx][ny] == 0) continue;
            visit[nx][ny] = true;
            q.push({nx, ny, c + 1});
        }
    }
    return -1;
}

/*
BFS를 이용하여 최단거리를 구해주었습니다.
*/