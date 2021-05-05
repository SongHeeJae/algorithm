#include <iostream>
#include <queue>
using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int n, m, k;
char map[1000][1001];
bool visit[1000][1000][10][2] = { false };

queue<vector<int>> q;

int bfs() {
	q.push({ 0, 0, 1, 0, 1 });
	visit[0][0][0][1] = true;
	while (!q.empty()) {
		int x = q.front()[0];
		int y = q.front()[1];
		int t = q.front()[2];
		int d = q.front()[3];
		int c = q.front()[4];
		q.pop();
		if (x == n - 1 && y == m - 1) return t;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (map[nx][ny] == '1') {
				if (d < k && c) {
					if (visit[nx][ny][d + 1][!c]) continue;
					q.push({ nx, ny, t + 1, d + 1, !c });
					visit[nx][ny][d + 1][!c] = true;
				}
			}
			else {
				if (visit[nx][ny][d][!c]) continue;
				q.push({ nx, ny, t + 1, d, !c });
				visit[nx][ny][d][!c] = true;
			}
		}
		if (visit[x][y][d][!c]) continue; // 제자리에서 밤낮만 바뀌는 경우
		q.push({ x, y, t + 1, d, !c });
		visit[x][y][d][!c] = true;
	}
	return -1;
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++)
		scanf("%s", map[i]);
	printf("%d", bfs());
}

/*
visit[방문한 x좌표][방문한 y좌표][벽을 부순 갯수][밤 또는 낮]을 가지고 BFS를 수행해주었습니다.
*/