#include <cstdio>

int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };

int n, m, ans = 1;
char map[50][51];
bool visit[50][50] = { false };

bool dfs(int x, int y, int d) {
	visit[x][y] = true;
	for (int i = 0; i < 4; i++) {
		if ((i + 2) % 4 == d) continue; // 이전에 지나친 지점 제외
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m || map[x][y] != map[nx][ny]) continue;
		if (visit[nx][ny]) return false;
		if(!dfs(nx, ny, i)) return false;
	}
	return true;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%s", map[i]);
	for (int i = 0; i < n && ans; i++) {
		for (int j = 0; j < m && ans; j++) {
			if (visit[i][j]) continue;
			if (!dfs(i, j, -1)) ans = 0;
		}
	}
	printf("%s", ans ? "No" : "Yes");
}

/*
같은 색의 공에 대해서 DFS를 돌릴 때, 이미 방문했던 지점을 한번 더 방문한다면 사이클이 있는 것입니다.
*/