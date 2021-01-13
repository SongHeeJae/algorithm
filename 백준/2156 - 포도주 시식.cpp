#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> grape(n + 1, 0);
	vector<int> dp(n + 1, 0);

	for (int i = 1; i <= n; i++) scanf("%d", &grape[i]);

	dp[1] = grape[1];
	if(n > 1) dp[2] = grape[1] + grape[2];
	for (int i = 3; i <= n; i++)
		dp[i] = max(max(dp[i - 3] + grape[i - 1], dp[i - 2]) + grape[i], dp[i-1]);
	printf("%d\n", dp[n]);
}