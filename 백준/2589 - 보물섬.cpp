#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, ans = -1;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int bfs(vector<vector<char>>& graph, int x, int y) {
	queue<pair<pair<int, int>, int>> q;
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	int xx, yy, t;
	q.push({ {x, y}, 0 });
	visited[x][y] = true;
	while (!q.empty()) {
		xx = q.front().first.first;
		yy = q.front().first.second;
		t = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = xx + dx[i];
			int ny = yy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < graph.size() && ny < graph[0].size()
				&& !visited[nx][ny] && graph[nx][ny] == 'L') {
				visited[nx][ny] = true;
				q.push({ {nx, ny}, t + 1 });
			}
		}
	}
	return t;
}

int main() {
	scanf("%d %d", &n, &m);
	vector<vector<char>> graph(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		getchar();
		for (int j = 0; j < m; j++) scanf("%c", &graph[i][j]);
	}
	for(int i=0; i<n; i++)
		for (int j = 0; j < m; j++)
			if (graph[i][j] == 'L') ans = max(bfs(graph, i, j), ans);
	printf("%d\n", ans);
}
