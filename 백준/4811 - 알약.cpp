#include <cstdio>
long long int dp[31] = { 1,1,2,5,14 };
int a;
int main() {
	for (int i = 5; i < 31; i++)
		for (int j = 0; j < i; j++)
			dp[i] += dp[j] * dp[i - j - 1];
	while (scanf("%d", &a) && a)
		printf("%lld\n", dp[a]);
} 

/*
카탈린 수라고 불리는 수열을 구해주었습니다.
*/