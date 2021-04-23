#include <vector>
#include <algorithm>
using namespace std;

int dfs(int x, int y, vector<vector<int>>& picture, int m, int n, int dx[], int dy[], bool visit[][100]) {
    visit[x][y] = true;
    int c = 1;
    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= m || ny >= n || visit[nx][ny] || picture[x][y] != picture[nx][ny]) continue;
        c += dfs(nx, ny, picture, m, n, dx, dy, visit);
    }
    return c;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};
    bool visit[100][100] = {false};
    int ans1 = 0, ans2 = 0;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n ;j++) {
            if(!visit[i][j] && picture[i][j] > 0) {
                ans1++;
                ans2 = max(ans2, dfs(i, j, picture, m, n, dx, dy, visit));
            }
        }
    }
    return {ans1, ans2};
}

/*
0이 아니면 동일한 영역에 대해서 dfs를 수행해주었습니다.
*/