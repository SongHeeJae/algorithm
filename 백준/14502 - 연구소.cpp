#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n, m, ans = -1;
int dx[] = { -1, 1, 0, 0 }; // 이동좌표
int dy[] = { 0, 0, -1, 1 };

void bfs(vector<vector<int>>& graph, int x, int y) {
	queue<pair<int, int>> q;
	graph[x][y] = -1;
	q.push({ x, y });
	while (!q.empty()) {
		int xx = q.front().first;
		int yy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = xx + dx[i];
			int ny = yy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m && graph[nx][ny] == 0) {
				graph[nx][ny] = -1;
				q.push({nx, ny});
			}
		}
	}
}

void safeZone(vector<vector<int>> graph) {
	int c = 0;
	for(int i=0; i<n; i++)
		for (int j = 0; j < m; j++)
			if (graph[i][j] == 2)
				bfs(graph, i, j);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!graph[i][j]) c++;
	ans = max(c, ans);
}

void wall(vector<vector<int>>& graph, int x, int y, int c) {
	if (c == 3) {
		safeZone(graph);
		return;
	}
	if (x >= n) return;
	int nx = y == m - 1 ? x + 1 : x;
	int ny = (y + 1) % m;
	if (graph[x][y] == 0) {
		graph[x][y] = 1;
		wall(graph, nx, ny, c + 1);
		graph[x][y] = 0;
	}
	wall(graph, nx, ny, c);
	
}

int main()
{
	scanf("%d %d", &n, &m);
	vector<vector<int>> graph(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) scanf("%d", &graph[i][j]);
	wall(graph, 0, 0, 0);
	printf("%d\n", ans);
}