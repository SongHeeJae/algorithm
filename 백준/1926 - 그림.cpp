#include <iostream>
#include <algorithm>

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int n, m, map[502][502] = { 0 };
int ans1 = 0, ans2 = 0;
bool visit[502][502] = { false };

int dfs(int x, int y) {
	visit[x][y] = true;
	int c = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (visit[nx][ny] || !map[nx][ny]) continue;
		c += dfs(nx, ny);
	}
	return c;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!visit[i][j] && map[i][j]) {
				ans1++;
				ans2 = std::max(ans2, dfs(i, j));
			}
		}
	}
	printf("%d\n%d", ans1, ans2);
}

/*
도화지에서 1이 나오면 dfs를 수행해주었습니다.
*/