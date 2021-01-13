#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void makePalindrome(vector<int>& nums, vector<vector<bool>>& dp) {
	int n = nums.size() - 1;
	for (int i = 1; i <= n; i++)
		dp[i][i] = true;

	for (int i = 1; i < n; i++)
		if (nums[i] == nums[i + 1]) dp[i][i + 1] = true;

	for (int i = 2; i < n; i++)
		for (int j = 1; i + j <= n; j++)
			if (nums[j] == nums[j + i] && dp[j + 1][j + i - 1])
				dp[j][j + i] = true;
}

int main() {
	int n, m, a;
	scanf("%d", &n);
	vector<int> nums(n + 1);
	for (int i = 1; i <= n; i++) scanf("%d", &nums[i]);

	vector<vector<bool>> dp(n+1, vector<bool>(n+1, false));
	makePalindrome(nums, dp);

	scanf("%d", &m);
	while (m--) {
		int s, e;
		scanf("%d %d", &s, &e);
		printf("%d\n", dp[s][e] ? 1 : 0);
	}
}