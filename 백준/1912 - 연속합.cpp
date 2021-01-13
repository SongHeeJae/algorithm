#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n, m = -1;
	scanf("%d", &n);
	vector<int> nums(n), dp(n, 0);
	for (int i = 0; i < n && scanf("%d", &nums[i]); i++);
	m = dp[0] = nums[0]; // i번째까지의 최댓값
	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] + nums[i], nums[i]);
		m = max(m, dp[i]);
	}
	printf("%d", m);
}