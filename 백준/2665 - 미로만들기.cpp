#include <iostream>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;
int map[50][50];
int visited[50][50];
int dx[] = { 1,-1, 0,0 };
int dy[] = { 0, 0, 1, -1 };
int n;
int bfs() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) visited[i][j] = INF;
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	visited[0][0] = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (map[nx][ny] == 1) {
				if (visited[nx][ny] > visited[x][y]) {
					visited[nx][ny] = visited[x][y];
					q.push({ nx, ny });
				}
			}
			else {
				if (visited[nx][ny] > visited[x][y] + 1) {
					visited[nx][ny] = visited[x][y] + 1;
					q.push({ nx, ny });
				}
			}
		}
	}
	return visited[n - 1][n - 1];
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	printf("%d", bfs());
}