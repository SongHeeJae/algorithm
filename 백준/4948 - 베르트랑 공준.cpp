#include <cstdio>
#include <cstring>
#define MAX 123456 * 2 + 1

int n, dp[MAX];

int main() {
	memset(dp, -1, sizeof(dp));
	dp[1] = 0;
	for (int i = 2; i <= MAX; i++) {
		if (dp[i] == -1) {
			dp[i] = 1;
			for (int j = i + i; j <= MAX; j += i) dp[j] = 0;
		}
		dp[i] += dp[i - 1];
		
	}
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		printf("%d\n", dp[2 * n] - dp[n]);
	}
}

/*
1 ~ N까지 소수 개수의 누적합을 저장해주었습니다.
*/