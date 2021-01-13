#include <iostream>
#include <cstring>
using namespace std;

int graph[500][500], dp[500][500];
int n, m;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int dfs(int x, int y) {
	if (x == n - 1 && y == m - 1) return 1;
	if (dp[x][y] != -1)  return dp[x][y];

	dp[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		if (graph[x][y] <= graph[nx][ny]) continue;
		dp[x][y] += dfs(nx, ny);
	}
	return dp[x][y];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
			dp[i][j] = -1;
		}
	cout << dfs(0, 0);
}
