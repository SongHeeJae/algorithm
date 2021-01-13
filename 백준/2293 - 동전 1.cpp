#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	vector<int> coin(n , 0);
	vector<int> dp(k + 1, 0);
	for (int i = 0; i < n; i++) scanf("%d", &coin[i]);
	dp[0] = 1; // 선택 x
	for (int i = 0; i < n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			dp[j] += dp[j - coin[i]];
		}
	}
	printf("%d\n", dp[k]);
}