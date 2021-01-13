#include <iostream>
#include <algorithm>
using namespace std;
int n;
long long int dp[101] = { 0 };
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i-1] + 1;
		for (int j = i - 3, k = 2; j >= 1; j--, k++)
			dp[i] = max(dp[i], dp[j] * k);
	}
	printf("%lld", dp[n]);
}

/*
dp[i]는 i번 눌렀을 때 최대로 출력된 A의 개수입니다.
1번 연산을 했을 때는, dp[i-1] + 1
4번 연산을 했을 때는, 2번과 3번 과정이 선행되어야하므로 dp[i-3]*2 입니다.
4번 연산에서는 내용이 버퍼에 복사되어있다면, 연달아서 4번 과정을 수행할 수 있으므로 dp[i-4]*3, dp[i-5]*4... 를 dp[i]까지 확인한 뒤에, 최댓값으로 업데이트해줬습니다.
*/