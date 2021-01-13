#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[] = { -1, 1 ,0 ,0 };
int dy[] = { 0, 0, -1, 1 };

int main() {
	int n, m, sx, sy, ex, ey, x, y, t, len, nx, ny, wx, wy, prev = -1;
	scanf("%d %d", &n, &m);
	char graph[50][50];
	queue<pair<int, int>> water_q;
	queue<pair<pair<int, int>, int>> q;
	for (int i = 0; i < n; i++) {
		getchar();
		for (int j = 0; j < m; j++) {
			scanf("%c", &graph[i][j]);
			if (graph[i][j] == 'S') {
				sx = i;
				sy = j;
			}
			else if (graph[i][j] == 'D') {
				ex = i;
				ey = j;
			}
			else if (graph[i][j] == '*') {
				water_q.push({ i, j });
			}
		}
	}
	q.push({ {sx, sy}, 0 });
	while (!q.empty()) {
		x = q.front().first.first;
		y = q.front().first.second;
		t = q.front().second;
		q.pop();
		if (x == ex && y == ey) {
			printf("%d\n", t);
			return 0;
		}
		if (prev != t) {
			len = water_q.size();
			while (len--) {
				wx = water_q.front().first;
				wy = water_q.front().second;
				water_q.pop();
				for (int i = 0; i < 4; i++) {
					nx = wx + dx[i];
					ny = wy + dy[i];
					if (nx >= 0 && ny >= 0 && nx < n && ny < m
						&& (graph[nx][ny] == '.' || graph[nx][ny] == 'S')) {
						water_q.push({ nx, ny });
						graph[nx][ny] = '*';
					}
				}
			}
			prev = t;
		}
		for (int i = 0; i < 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m
				&& (graph[nx][ny] == '.' || graph[nx][ny] == 'D')) {
				graph[nx][ny] = ',';
				q.push({ {nx, ny}, t + 1 });
			}
		}
	}
	printf("KAKTUS\n");
}
