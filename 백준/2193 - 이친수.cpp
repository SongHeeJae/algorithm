#include <cstdio>
int main() {
	int n;
	long long int dp[90][2] = { 0,1 }, s = 10;
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i-1][1];
		dp[i][1] = dp[i - 1][0];
	}
	printf("%lld", dp[n - 1][0] + dp[n - 1][1]);
}

/*
수의 끝이 1이라면 0만 붙일 수 있고,

수이 끝이 0이라면 0과 1을 붙일 수 있습니다.

dp[i][j]는 수 (i+1)에서 수의 끝이 j(0또는1)로 끝나는 경우의 수 입니다.
dp[i][0] = dp[i-1][0] + dp[i-1][1];
dp[i][1] = dp[i-1][0]

경우의 수는 dp[i][0] + dp[i][1] 입니다.

그런데 제출하고보니 dp[i] = dp[i-1] + dp[i-2]가 더 간단하게 성립합니다.
*/