#include <cstdio>
int main() {
	int n, dp[1001] = {0, 1, 3};
	scanf("%d", &n);
	for (int i = 3; i <= n; i++)
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
	printf("%d", dp[n]);
}

/*
2*i 크기의 타일을 채울 때는,

i-1 크기의 타일에서 2*1의 타일을 하나 덧붙여주거나,

i-2 크기의 타일에서 2*2의 타일 하나를 덧붙여주거나,

i-2 크기의 타일에서 1*2의 타일 두개를 덧붙여줄 수 있습니다.

(2*1 타일 두개는 i-1 크기의 타일에서 2*1의 타일을 하나 덧붙여주는 것과 중복)

따라서, dp[i] = dp[i-1] + 2 * dp[i-2];
*/