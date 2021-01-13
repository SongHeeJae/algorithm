#include <iostream>
#include <queue>
using namespace std;

int map[500][500] = { 0, };
bool visited[500][500] = { false, };
int n, m, a, b, k, sx, sy, ex, ey;
int dx[] = { -1,1,0,0 };
int dy[] = { 0, 0, -1,1 };

bool isPossible(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m) return false;
    if (visited[x][y]) return false;
    for (int i = x; i < x + a; i++) {
        for (int j = y; j < y + b; j++) {
            if (i >= n || j >= m || map[i][j] == 1) return false;
        }
    }
    return true;
}

int bfs() {
    queue<pair<pair<int, int>, int>> q;
    visited[sx-1][sy-1] = true;
    q.push({ {sx-1, sy-1}, 0 });
    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int c = q.front().second;
        q.pop();
        if (x == ex-1 && y == ey-1) return c;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isPossible(nx, ny)) {
                visited[nx][ny] = true;
                q.push({ {nx, ny}, c + 1 });
            }
        }
    }
    return -1;
}

int main() {
    scanf("%d %d %d %d %d", &n, &m, &a, &b, &k);
    while(k-- && scanf("%d %d", &sx, &sy)) map[sx-1][sy-1] = 1;
    scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
    printf("%d\n", bfs());
}