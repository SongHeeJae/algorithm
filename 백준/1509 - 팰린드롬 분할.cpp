#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void makePalindrome(string& str, vector<vector<bool>>& dp) {
	int n = str.length() - 1;
	for (int i = 1; i <= n; i++)
		dp[i][i] = true;

	for (int i = 1; i < n; i++)
		if (str[i] == str[i + 1]) dp[i][i + 1] = true;

	for (int i = 2; i < n; i++)
		for (int j = 1; i + j <= n; j++)
			if (str[j] == str[j + i] && dp[j + 1][j + i - 1])
				dp[j][j + i] = true;
}

int main() {
	string str;
	cin >> str;
	str.insert(0, " ");
	vector<vector<bool>> dp(str.length(), vector<bool>(str.length(), false));
	makePalindrome(str, dp);

	vector<int> c(str.length(), 0);

	for (int i = 1; i < str.length(); i++) {
		c[i] = 987654321;
		for (int j = 1; j <= i; j++) {
			if (dp[j][i]) c[i] = min(c[i], c[j - 1] + 1);
		}
	}
	printf("%d\n", c[c.size() - 1]);
}