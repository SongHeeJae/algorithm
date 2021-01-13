#include <iostream>
#include <algorithm>
int main() {
	int n, p[1001] = { 0 }, dp[1001] = { 0 };
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			dp[i] = std::max(dp[i], dp[i-j] + p[j]);
	printf("%d", dp[n]);

}

/*
1개 최대 가격 : max(dp[1], p[1] + dp[0])

2개 최대 가격 : max(dp[2], p[1] + dp[1], p[2] + dp[0])

3개 최대 가격 : max(dp[3], p[1] + dp[2], p[2] + dp[1], p[3] + dp[0])

n개 최대 가격 : max(dp[n], p[1...n] + dp[(n-1)...0])
*/