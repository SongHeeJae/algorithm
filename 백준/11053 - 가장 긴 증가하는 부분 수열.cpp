#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, result = 0;
	scanf("%d", &n);
	vector<int> nums(n + 1);
	vector<int> dp(n + 1);
	for (int i = 1; i <= n; i++)
		scanf("%d", &nums[i]);

	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (nums[j] < nums[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		result = max(dp[i], result);
	}

	printf("%d\n", result);
}