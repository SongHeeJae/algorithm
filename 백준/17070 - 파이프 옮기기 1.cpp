#include <cstdio>
int n, c = 0;
int map[16][16];
int dx[] = { 0, 1, 1 };
int dy[] = { 1, 0, 1 };

void dfs(int x, int y, int dir) {
	if (x == n - 1 && y == n - 1) {
		c++;
		return;
	}
	for (int i = 0; i < 3; i++) {
		if (dir == 0 && i == 1 || dir == 1 && i == 0) // 가로, 세로
			continue;
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= n || ny >= n) continue;
		if (map[nx][ny]) continue;
		if (i == 2 && (map[nx - 1][ny] || map[nx][ny - 1])) continue;
		dfs(nx, ny, i);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) scanf("%d", &map[i][j]);
	dfs(0, 1, 0);
	printf("%d", c);
}

/*
파이프 옮기는 특성 상 이전의 위치로 돌아갈 상황은 없었습니다. dfs를 이용하여 구현하였습니다.

*/