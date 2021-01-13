#include <cstdio>
#include <cstring>
int w, h, map[50][50];
bool visit[50][50];
int dx[] = { -1,1,0,0, 1,1,-1,-1 };
int dy[] = { 0, 0, -1,1, 1,-1,1,-1 };
void dfs(int x, int y) {
	visit[x][y] = true;
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
		if (map[nx][ny] && !visit[nx][ny]) dfs(nx, ny);
	}
}
int main() {
	while (scanf("%d %d", &w, &h) && w != 0) {
		int c = 0;
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++) scanf("%d", &map[i][j]);
		memset(visit, false, sizeof(visit));
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				if (!visit[i][j] && map[i][j]) {
					dfs(i, j);
					c++;
				}
		printf("%d\n", c);
	}
}

/*
w와 h 입력 순서, 8방향 이동만 주의해주면 됩니다.
*/