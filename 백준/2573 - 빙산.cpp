#include <iostream>
#include <vector>
using namespace std;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void dfs(vector<vector<int>>& graph, vector<vector<bool>>& visited, int x, int y) {
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!visited[nx][ny] && graph[nx][ny] > 0)
			dfs(graph, visited, nx, ny);
	}
}

int main() {
	int n, m, y = 0;
	scanf("%d %d", &n, &m);
	vector<vector<int>> graph(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) scanf("%d", &graph[i][j]);
	while (1) {
		vector<int> temp;
		for(int i=0; i<n; i++)
			for (int j = 0; j < m; j++) {
				if (graph[i][j] > 0) {
					int c = 0;
					for (int k = 0; k < 4; k++) {
						int nx = i + dx[k];
						int ny = j + dy[k];
						if (nx >= 0 && ny >= 0 && nx < n && ny < m && graph[nx][ny] <= 0) c++;
					}
					temp.push_back(c);
				}
			}
		if (temp.size() == 0) {
			printf("0\n");
			return 0;
		}
		y++;
		int k = 0;
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				if (graph[i][j] > 0) graph[i][j] -= temp[k++];
		bool flag = false;
		vector<vector<bool>> visited(n, vector<bool>(m, false));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (!visited[i][j] && graph[i][j] > 0) {
					if (flag) {
						printf("%d\n", y);
						return 0;
					}
					flag = true;
					dfs(graph, visited, i, j);
				}
	}
}
