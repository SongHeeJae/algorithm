#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<vector<int>> dp(n, vector<int>(10));

	dp[0] = { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

	for (int i = 1; i < n; i++) {
		dp[i][0] = dp[i - 1][1] % 1000000000;
		dp[i][9] = dp[i - 1][8] % 1000000000;
		for (int j = 1; j <= 8; j++)
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
	}

	int sum = 0;
	for (int i = 0; i < 10; i++) sum = (sum + dp[n - 1][i]) % 1000000000;
	printf("%d\n", sum);

}