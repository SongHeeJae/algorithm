#include <iostream>
#include <algorithm>
using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int n, ans = 1;
int map[500][500];
int visit[500][500] = { 0 };

int dfs(int x, int y) {
	if (visit[x][y]) return visit[x][y];
	visit[x][y]++;
	int m = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		if (map[nx][ny] <= map[x][y]) continue;
		m = max(m, dfs(nx, ny));
	}
	return visit[x][y] += m;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &map[i][j]);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ans = max(ans, dfs(i, j));
	printf("%d", ans);
}

/*
visit[x][y]는 (x,y) 지점에서 출발했을 때의 최대 생존 일수를 저장해줍니다.
이미 최대 생존 일수가 저장되어있다면, 그대로 재활용하면됩니다.
저장되어있지않다면, 현재 지점의 생존 일수를 1로 처리하고, 이동 가능한 다음 지점들의 생존 일수의 최댓값을 현재 지점의 생존 일수에 더해주면 됩니다.
*/