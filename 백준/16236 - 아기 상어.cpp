#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

int graph[20][20];
bool visited[20][20];
int n, sx, sy, s = 2, t = 0, cnt = 0, x, y, c, f=1, d;
int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n && scanf("%d", &graph[i][j]); j++)
			if (graph[i][j] == 9) {
				sx = i;
				sy = j;
				graph[i][j] = 0;
			}
	while (1) {
		if (s == cnt) {
			s++;
			cnt = 0;
		}
		memset(visited, false, sizeof(visited));
		queue<pair<pair<int, int>, int>> q;
		q.push({ {sx, sy}, 0 });
		visited[sx][sy] = true;
		while (!q.empty()) {
			x = q.front().first.first;
			y = q.front().first.second;
			c = q.front().second;
			q.pop();
			if (graph[x][y] > 0 && graph[x][y] < s) {
				if (f) {
					d = c;
					sx = x;
					sy = y;
				}
				if (d != c) break;
				if (x < sx || (x == sx && y < sy)) {
					sx = x;
					sy = y;
				}
				f = 0;
			}
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
				if (visited[nx][ny]) continue;
				if (graph[nx][ny] > s) continue;
				q.push({ {nx, ny}, c + 1 });
				visited[nx][ny] = true;
			}
		}
		if (f++) break;
		t += d;
		graph[sx][sy] = 0;
		cnt++;
	}
	printf("%d", t);
}