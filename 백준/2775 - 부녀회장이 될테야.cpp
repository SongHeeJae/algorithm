#include <cstdio>

int t, k, n, dp[15][15] = { 0 };

int f(int k, int n) {
	int& ret = dp[k][n];
	if (k == 0) return ret = n;
	if (n == 1) return ret = 1;
	if (ret) return ret;
	return ret = f(k - 1, n) + f(k, n - 1);
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &k, &n);
		printf("%d\n", f(k, n));
	}
}

/*
dp를 이용하여 풀었습니다.
*/