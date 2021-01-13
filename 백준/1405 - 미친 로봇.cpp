#include <iostream>

int graph[29][29];
bool visited[29][29] = { false, };
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n, a;
double p[4];
double ans = 0;

void dfs(int x, int y, int c, double pe) {
	if (c == n) {
		ans += pe;
		return;
	}
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!visited[nx][ny]) {
			dfs(nx, ny, c + 1, pe * p[i]);
		}
	}
	visited[x][y] = false;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < 4; i++) {
		scanf("%d", &a);
		p[i] = a / 100.0;
	}

	dfs(14, 14, 0, 1.0);
	printf("%.10lf", ans);
}