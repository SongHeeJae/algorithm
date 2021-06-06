#include <iostream>
#include <queue>
using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int n, m, sx, sy, sd, ex, ey, ed, map[101][101];
bool visit[101][101][5] = { false };
queue<vector<int>> q;

int rotate(int d, bool right) {
	if (d == 1) return right ? 3 : 4;
	else if (d == 2) return right ? 4 : 3;
	else if (d == 3) return right ? 2 : 1;
	else return right ? 1 : 2;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &map[i][j]);
	scanf("%d %d %d %d %d %d", &sx, &sy, &sd, &ex, &ey, &ed);

	q.push({ sx, sy, sd, 0});
	visit[sx][sy][sd] = true;

	while (!q.empty()) {
		int x = q.front()[0];
		int y = q.front()[1];
		int d = q.front()[2];
		int c = q.front()[3];
		q.pop();
		if (x == ex && y == ey && d == ed) {
			printf("%d", c);
			return 0;
		}
		for (int i = 1; i <= 3; i++) {
			int nx = x + dx[d - 1] * i;
			int ny = y + dy[d - 1] * i;
			if (nx < 1 || ny < 1 || nx > n || ny > m || visit[nx][ny][d]) continue;
			if (map[nx][ny] == 1) break;
			q.push({ nx, ny, d, c + 1 });
			visit[nx][ny][d] = true;
		}
		int ld = rotate(d, false);
		int rd = rotate(d, true);
		if (!visit[x][y][ld]) {
			q.push({ x, y, ld, c + 1 });
			visit[x][y][ld] = true;
		}
		if (!visit[x][y][rd]) {
			q.push({ x, y, rd, c + 1 });
			visit[x][y][rd] = true;
		}
	}
}