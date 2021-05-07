#include <iostream>
#include <algorithm>
#define INF 2147483647
using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int n, m, ans = INF;
char map[21][21];
bool visit[20][20][20][20] = { false };

bool isFinished(int x, int y) {
	return x < 1 || y < 1 || x > n || y > m;
}

void dfs(int x1, int y1, int x2, int y2, int depth) {
	if (depth > 10 || depth >= ans) return;
	bool flag1 = isFinished(x1, y1);
	bool flag2 = isFinished(x2, y2);
	if (flag1 ^ flag2) { // 두 동전 중 하나만 떨어지면 성공
		ans = min(ans, depth);
		return;
	}
	if (flag1 && flag2) return; // 둘 다 떨어지면 실패
	visit[x1][y1][x2][y2] = true;
	for (int i = 0; i < 4; i++) {
		int nx1 = x1 + dx[i];
		int ny1 = y1 + dy[i];
		int nx2 = x2 + dx[i];
		int ny2 = y2 + dy[i];
		if (map[nx1][ny1] == '#') nx1 -= dx[i], ny1 -= dy[i]; // 벽이면 복구
		if (map[nx2][ny2] == '#') nx2 -= dx[i], ny2 -= dy[i];
        // 두 구슬이 겹치면 하나만 떨어뜨릴 수 없음
		if ((nx1 == nx2 && ny1 == ny2) || visit[nx1][ny1][nx2][ny2]) continue;
		dfs(nx1, ny1, nx2, ny2, depth + 1);
	}
	visit[x1][y1][x2][y2] = false;
}

int main() {
	int x1 = -1, y1, x2, y2;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &map[i][j]);
			if (map[i][j] == 'o') {
				if (x1 == -1) x1 = i, y1 = j;
				else x2 = i, y2 = j;
			}
		}
	}
	dfs(x1, y1, x2, y2, 0);
	printf("%d", ans != INF ? ans : -1);
}

/*
각 방향으로 이동하는 구슬의 좌표를 기억해둔 뒤, 게임을 끝낼 수 있는지 확인해주었습니다.
*/