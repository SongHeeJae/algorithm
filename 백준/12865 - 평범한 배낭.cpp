#include <iostream>
#include <algorithm>
using namespace std;

int n, k, w[101], v[101], dp[100001] = { 0 };

int main() {

	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &w[i], &v[i]);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = k; j >= w[i]; j--) {
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}

	printf("%d", dp[k]);
}

/*
어떤 물건의 무게가 w, 가치가 v일 때,
dp[i] = max(dp[i], dp[i - w] + v);  (i - w >= 0) // 배낭에 담은 무게가 i일 때, 얻을 수 있는 물건들의 최대 가치
물건을 넣은 경우 또는 넣지 않았을 경우 중에 더 높은 가치를 저장해줍니다.
안쪽 반복문을 정방향으로 수행하면 이미 갱신된 값을 사용하면서 동일한 물건을 중복해서 선택할 수 있게 되므로, 역방향으로 수행해주었습니다.
*/