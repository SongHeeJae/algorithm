#include <cstdio>
int n, map[100][100];
long long int dp[100][100] = { 0 };
long long int f(int x, int y) {
	if (x == n-1 && y == n-1) return 1;
	if (dp[x][y] == 0 && map[x][y] != 0) { // 방문하지 않았던 지점, 이동 거리 1 이상인 경우
		int xx = x + map[x][y];
		int yy = y + map[x][y];
		if (xx < n) dp[x][y] += f(xx, y);
		if (yy < n) dp[x][y] += f(x, yy);
	}
	return dp[x][y];
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) scanf("%d", &map[i][j]);
	printf("%lld", f(0, 0));
}

/*

최초 경로에 대해서는 DP를 이용하여 가능한 경로를 탐색하여 기억해두고,

중복 경로에 대해서는 그 경로의 가능한 경로 수를 그대로 더해주었습니다. 
*/