#include <iostream>
using namespace std;

int n, k;
int dp[201] = { 1, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= n; j++) dp[j] = (dp[j - 1] + dp[j]) % 1000000000;
		
	cout << dp[n];
}
