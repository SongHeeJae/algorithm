#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n, a[1001], dp[1001] = { 0, 1 }, s = 1;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 2; i <= n; i++) {
		dp[i] = 1;
		for (int j = i-1; j >= 0; j--)
			if (a[j] > a[i]) dp[i] = max(dp[i], 1 + dp[j]);
		s = max(dp[i], s);
	}
	printf("%d", s);
}