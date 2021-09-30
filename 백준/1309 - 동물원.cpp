#include <iostream>
#include <algorithm>
using namespace std;
#define MOD 9901
int main() {
	int n, ans = 0, dp[3] = { 1, 3, 7 };
	scanf("%d", &n);
	for (int i = 3; i <= n; i++) {
		int val = (dp[2] * 3 - dp[1] - dp[0] + MOD * 2) % MOD;
		dp[0] = dp[1];
		dp[1] = dp[2];
		dp[2] = val;
	}
	printf("%d", dp[min(n, 2)] % MOD);
}

/*
dp[i] = dp[i - 1] * 3 - dp[i - 2] - dp[i - 3]
두 번의 뺄셈 연산에서 나머지 연산이 적용될 수 있도록 MOD * 2를 더한 상태에서 나머지를 구해주었습니다. 
*/