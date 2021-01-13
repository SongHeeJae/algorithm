#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int main() {
	int n, m, sx, sy;
	scanf("%d %d", &n, &m);
	vector<vector<char>> graph(n, vector<char>(m));
	queue<pair<int, int>> fire_q;
	queue<pair<pair<int, int>, int>> q;
	for (int i = 0; i < n; i++) {
		getchar();
		for (int j = 0; j < m; j++) {
			scanf("%c", &graph[i][j]);
			if (graph[i][j] == 'J') {
				sx = i;
				sy = j;
			}
			else if (graph[i][j] == 'F') {
				fire_q.push({ i, j });
			}
		}
	}
	q.push({ {sx, sy}, 1 });
	int prev = 0;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int t = q.front().second;
		if (x == 0 || y == 0 || x == n - 1 || y == m - 1) {
			printf("%d", t);
			return 0;
		}
		q.pop();
		if (t != prev) {
			int len = fire_q.size();
			while (len--) {
				int fx = fire_q.front().first;
				int fy = fire_q.front().second;
				fire_q.pop();
				for (int i = 0; i < 4; i++) {
					int nx = fx + dx[i];
					int ny = fy + dy[i];
					if (nx >= 0 && ny >= 0 && nx < n && ny < m
						&& (graph[nx][ny] == '.' || graph[nx][ny] == 'J')) {
						graph[nx][ny] = 'F';
						fire_q.push({ nx, ny });
					}
				}
			}
			prev = t;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m
				&& (graph[nx][ny] == '.')) {
				graph[nx][ny] = ',';
				q.push({ { nx, ny }, t + 1});
			}
		}
	}
	printf("IMPOSSIBLE");
	
}
