#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int graph[100][100];
bool visited[100][100] = { false, };
int n;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int ans = 987654321;

void dfs(int x, int y, int k) {
	visited[x][y] = true;
	graph[x][y] = k;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		if (!visited[nx][ny] && graph[nx][ny] != 0) {
			dfs(nx, ny, k);
		}
	}
}

void bfs(int x, int y, int k) {
	bool visited[100][100] = { false, };
	queue<pair<pair<int, int>, int>> q;
	q.push({ { x, y }, 0 });
	visited[x][y] = true;
	int xx, yy, c;
	while (!q.empty()) {
		xx = q.front().first.first;
		yy = q.front().first.second;
		c = q.front().second;
		if (graph[xx][yy] != k && graph[xx][yy] != 0) {
			ans = min(c, ans);
			break;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = xx + dx[i];
			int ny = yy + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (!visited[nx][ny] && graph[nx][ny] != k) {
				visited[nx][ny] = true;
				q.push({ {nx, ny}, c + 1 });
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &graph[i][j]);

	int k = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (!visited[i][j] && graph[i][j] != 0)
				dfs(i, j, k++);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (visited[i][j]) {
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
					if (!visited[nx][ny]) 
						bfs(nx, ny, graph[i][j]);
				}
			}
	printf("%d", ans);
}