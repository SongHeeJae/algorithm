#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n, t[15], p[15], dp[15], ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n && scanf("%d %d", &t[i], &p[i]); i++);
	for (int i = 0; i < n; i++) dp[i] = p[i];
	for (int i = 0; i < n; ans = t[i] + i <= n ? max(dp[i], ans) : ans, i++)
		for (int j = 0; j < i; j++)
			dp[i] = j + t[j] <= i ? max(dp[i], p[i] + dp[j]) : dp[i];
	printf("%d", ans);
}