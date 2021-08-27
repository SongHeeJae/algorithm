#include <iostream>
#include <algorithm>
#include <cstring>
#define INF 1e6
using namespace std;

int n, ans = INF;
int rgb[3][3], dp[1001][3], cost[1001][3];

int main() {

	memset(dp, 0, sizeof(dp));
	memset(rgb, 0x07, sizeof(rgb));

	scanf("%d", &n);
	scanf("%d %d %d", &rgb[0][0], &rgb[1][1], &rgb[2][2]);
	for (int i = 2; i <= n; i++) {
		scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			dp[1][j] = rgb[i][j];
		}
		for (int j = 2; j <= n; j++) {
			dp[j][0] = min(dp[j - 1][1], dp[j - 1][2]) + cost[j][0];
			dp[j][1] = min(dp[j - 1][0], dp[j - 1][2]) + cost[j][1];
			dp[j][2] = min(dp[j - 1][0], dp[j - 1][1]) + cost[j][2];
		}
		dp[n][i] = INF;
		ans = min({ans, dp[n][0], dp[n][1], dp[n][2]});
	}
	printf("%d", ans);
}

/*
첫 번째 집을 빨강, 초록, 파랑 중 하나의 색으로 칠한 각각의 경우에,
N번째 집을 칠했을 때의 최소 누적 비용을 구해주었습니다.
*/