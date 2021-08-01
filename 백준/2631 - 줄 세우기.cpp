#include <iostream>
#include <algorithm>
using namespace std;

int n, m, arr[201], dp[201];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (arr[j] < arr[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		m = max(m, dp[i]);
	}
	printf("%d", n - m);
}

/*
아이들을 번호순으로 오름차순 정렬시키는데 필요한 최소 이동 횟수를 구해야합니다.
아이들은 원하는 위치로 이동할 수 있고, 이미 세워진 아이들 중 일부는 이미 오름차순으로 정렬된 상태에 있습니다.
그러므로 주어진 번호에서 가장 긴 증가하는 부분 수열의 길이를 구해주면, 이 아이들은 이미 오름차순으로 정렬되어있으므로 그 순서를 유지해도 됩니다.
따라서, (전체 아이의 수 - 가장 긴 증가하는 부분 수열의 길이)번 만큼 아이들을 이동시켜주면 됩니다.
*/