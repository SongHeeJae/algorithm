#include <algorithm>
#include <iostream>
#define INF 987654321
using namespace std;
int n, k, a, dp[10001] = { 0 };
int main() {
	scanf("%d %d", &n, &k);
	while (n-- && scanf("%d", &a)) 
		if(a < 10001) dp[a] = 1;
	for (int i = 1; i <= k; i++) {
		if(!dp[i]) dp[i] = INF;
		for (int j = 1; j <= i / 2; j++)
			dp[i] = min(dp[i], dp[j] + dp[i - j]);
	}
	printf("%d", dp[k] != INF ? dp[k] : -1);
}

/*
dp[i]는 i원을 만들 수 있는 최소 동전의 개수입니다.
초기에 제시된 동전의 가치로는, 각 가치의 동전을 1개로 만들 수 있습니다.
k <= 10000 이므로, 동전의 가치가 10000원을 넘어간다면, 굳이 저장을 안해줬습니다.
dp[i]는 현재까지 가능한 최소 동전의 개수로 계속 업데이트해주었습니다.
*/