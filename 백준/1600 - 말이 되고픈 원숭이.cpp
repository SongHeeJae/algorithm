#include <iostream>
#include <queue>
using namespace std;

int dx[] = { -1,1,0,0,-2,-2,-1,-1,1,1,2,2 };
int dy[] = { 0,0,-1,1,1,-1,-2,2,-2,2,-1,1 };

int k, w, h;
int map[200][200];
bool visit[200][200][31] = { false };

int bfs() {
	queue<vector<int>> q;
	q.push({ 0, 0, 0, 0 });
	visit[0][0][0] = true;
	while (!q.empty()) {
		int x = q.front()[0];
		int y = q.front()[1];
		int c = q.front()[2];
		int t = q.front()[3];
		q.pop();
		if (x == h - 1 && y == w - 1) return t;
		int dc = c < k ? 12 : 4;
		for (int i = 0; i < dc; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nc = c + (i > 3);
			if (nx < 0 || ny < 0 || nx >= h || ny >= w || map[nx][ny] || visit[nx][ny][nc]) continue;
			q.push({ nx, ny, nc, t + 1 });
			visit[nx][ny][nc] = true;
		}
	}
	return -1;
}

int main() {
	scanf("%d %d %d", &k, &w, &h);
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			scanf("%d", &map[i][j]);
	printf("%d", bfs());
}