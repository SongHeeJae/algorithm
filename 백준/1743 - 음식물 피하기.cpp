#include <iostream>
#include <algorithm>
#define MAX 102
using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int n, m, k, a, b, ans = 0;
bool map[MAX][MAX] = { false };

int dfs(int x, int y) {
	int c = 1;
	map[x][y] = false;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!map[nx][ny]) continue;
		c += dfs(nx, ny);
	}
	return c;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> k;
	while (k--) {
		cin >> a >> b;
		map[a][b] = true;
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (map[i][j])
				ans = max(ans, dfs(i, j));

	cout << ans;
}

/*
dfs로 가장 큰 영역의 넓이를 구해주었습니다.
*/