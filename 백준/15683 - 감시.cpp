#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int graph[8][8];
int ans = 987654321;
vector<pair<int, int>> pos;

void cctv(int x, int y, int f) {
	if (f == 0) {
		for (int i = y; i >= 0 && graph[x][i] != 6; i--)
			if (graph[x][i] == 0) graph[x][i] = -1;
	}
	else if (f == 1) {
		for (int i = y; i < m && graph[x][i] != 6; i++)
			if (graph[x][i] == 0) graph[x][i] = -1;
	}
	else if (f == 2) {
		for (int i = x; i >= 0 && graph[i][y] != 6; i--)
			if (graph[i][y] == 0) graph[i][y] = -1;
	}
	else {
		for (int i = x; i < n && graph[i][y] != 6; i++) {
			if (graph[i][y] == 0) graph[i][y] = -1;
		}
	}
}

void copy(int a[][8], int b[][8]) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) a[i][j] = b[i][j];
}

void dfs(int c) {
	
	if (c == pos.size()) {
		int cnt = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (graph[i][j] == 0) cnt++;
		ans = min(ans, cnt);
		return;
	}

	int x = pos[c].first;
	int y = pos[c].second;
	int prev[8][8];
	copy(prev, graph);

	if (graph[x][y] == 1) {
		for (int i = 0; i < 4; i++) {
			cctv(x, y, i);
			dfs(c + 1);
			copy(graph, prev);
		}
	}
	else if (graph[x][y] == 2) {
		for (int i = 0; i < 2; i++) {
			cctv(x, y, i * 2);
			cctv(x, y, i * 2 + 1);
			dfs(c + 1);
			copy(graph, prev);
		}
	}
	else if (graph[x][y] == 3) {
		for (int i = 0; i < 2; i++) {
			for (int j = 2; j < 4; j++) {
				cctv(x, y, i);
				cctv(x, y, j);
				dfs(c + 1);
				copy(graph, prev);
			}
		}
	}
	else if (graph[x][y] == 4) {
		for (int i = 0; i < 2; i++) {
			int k = i == 0 ? 2 : 0;
			for (int j = k; j < k + 2; j++) {
				cctv(x, y, i * 2);
				cctv(x, y, i * 2 + 1);
				cctv(x, y, j);
				dfs(c + 1);
				copy(graph, prev);
			}
			
		}
	}
	else {
		for (int i = 0; i < 4; i++) cctv(x, y, i);
		dfs(c + 1);
		copy(graph, prev);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf("%d", &graph[i][j]);
			if (graph[i][j] != 0 && graph[i][j] != 6)
				pos.push_back({ i, j });
		}
	dfs(0);
	printf("%d", ans);
}
