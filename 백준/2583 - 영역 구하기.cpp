#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void drawRectangle(vector<vector<int>>& graph, int a, int b, int c, int d) {
	for (int i = a; i < c; i++)
		for (int j = b; j < d; j++) graph[i][j] = 1;
}

int dfs(vector<vector<int>>& graph, int x, int y) {
	int c = 1;
	graph[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < graph.size() && ny < graph[0].size() && graph[nx][ny] == 0) {
			graph[nx][ny] = 1;
			c += dfs(graph, nx, ny);
		}
	}
	return c;
}

int main() {
	int n, m, k, a, b, c, d;
	scanf("%d %d %d", &n, &m, &k);
	vector<vector<int>> graph(n, vector<int>(m, 0));
	while (k-- && scanf("%d %d %d %d", &a, &b, &c, &d)) drawRectangle(graph, b, a, d, c);
	vector<int> ans;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (graph[i][j] == 0) ans.push_back(dfs(graph, i, j));
	sort(ans.begin(), ans.end());
	printf("%d\n", (int)ans.size());
	for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
}
