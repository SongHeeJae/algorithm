#include <iostream>
#include <algorithm>
#include <cstring>
#define N_INF 0xfefefefe
using namespace std;

int dx[] = { 1, 0, 0 };
int dy[] = { 0, -1, 1 };

int n, m;
int map[1001][1001];
int dp[1001][1001][3];

int dfs(int x, int y, int dir) {
	int& res = dp[x][y][dir];

	if (x == n && y == m) {
		return map[x][y];
	}

	if (res != N_INF) {
		return res;
	}
	
	for (int i = 0; i < 3; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 1 || ny < 1 || nx > n || ny > m || i * dir == 2) continue;
		res = max(res, dfs(nx, ny, i));
	}
	return res += map[x][y];
}


int main() {
	memset(dp, 0xfe, sizeof(dp));

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	printf("%d", dfs(1, 1, 0));
}

/*
각 지점에서 다음 지점으로 이동하면서 도착 지점을 다녀왔을 때의 최대 비용을 상좌우 방향 별로 기억해주었습니다. 
*/