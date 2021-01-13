#include <iostream>
#include <algorithm>
#include <cstring>
#define INF 97654321
int main() {
	int n, p[1001] = { 0 }, dp[1001];
	memset(dp, INF, sizeof(dp));
	dp[0] = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			dp[i] = std::min(dp[i], dp[i-j] + p[j]);
	printf("%d", dp[n]);

}