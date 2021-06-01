#include <cstdio>

int t, n;
long long dp[65][10] = { 0 };

int main() {
	for (int i = 0; i < 10; i++) dp[1][i] = 1;
	for (int i = 2; i <= 64; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = j; k < 10; k++) {
				dp[i][j] += dp[i - 1][k];
			}
		}
	}
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		long long int s = 0;
		for (int i = 0; i < 10; i++) s += dp[n][i];
		printf("%lld\n", s);
	}
}

/*
dp[i][j] = i자리수에서 첫 자리가 j로 시작할 때의 개수입니다.

dp[1][0] ~ dp[1][9]는 1로 초기화해줍니다.
dp[2][0]은 첫 자리가 0이므로 뒤에는 한 자리수에서 첫 자리가 0~9로 시작할 때의 수가 올 수 있습니다.
dp[2][1]은 첫 자리가 1이므로 뒤에는 한 자리수에서 첫 자리가 1~9로 시작할 때의 수가 올 수 있습니다.
...
dp[3][0]은 첫 자리가 0이므로 뒤에는 두 자리수에서 첫 자리가 0으로 시작할 때의 수가 올 수 있습니다.

따라서, dp[i][j] = (dp[i-1][j] ~ dp[i-1][9])의 합입니다.
*/