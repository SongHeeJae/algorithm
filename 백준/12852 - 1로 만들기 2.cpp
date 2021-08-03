#include <iostream>
#include <algorithm>
#define INF 2147483647
using namespace std;

int n, dp[1000001] = { 0 };
int main() {
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
        dp[i] = INF;
		if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
		if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
		dp[i] = min(dp[i], dp[i - 1] + 1);
	}

	printf("%d\n", dp[n]);
	while (n > 0) {
		printf("%d ", n);
		int nn = n - 1;
		if (n % 3 == 0 && dp[nn] > dp[n / 3]) nn = n / 3;
		if (n % 2 == 0 && dp[nn] > dp[n / 2]) nn = n / 2;
		n = nn;
	}
}

/*
dp[i] = i를 만드는 연산의 최소 횟수를 저장해줍니다.
이 값을 이용하여 dp[1]부터 dp[n]까지 만들어낸 과정을 역추적해주었습니다.
*/