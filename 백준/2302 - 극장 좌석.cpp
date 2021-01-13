#include <cstdio>
#include <cmath>

int n, m, k, c = 1;
int vip[41] = { 0 };
int dp[41] = { 1,1 };

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &k);
		vip[i] = k;
	}
	for (int i = 2; i <= n; i++)
		dp[i] = dp[i - 1] + dp[i - 2];

	for (int i = 1; i <= m; i++)
		c *= dp[vip[i] - vip[i - 1] - 1];
	printf("%d", c * dp[n - vip[m]]);
}

/*
브루트포스로 풀었다가 시간초과가 났었습니다. dp문제였습니다.

각 vip석 사이의 가능한 좌석 경우의 수는 피보나치 수열로 증가하였습니다.

이를 이용하여 각 vip석 사이의 가능한 좌석 경우의 수를 모두 곱하였습니다.

*/