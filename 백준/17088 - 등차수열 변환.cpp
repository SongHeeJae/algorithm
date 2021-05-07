#include <iostream>
#include <algorithm>
#define INF 2147483647
using namespace std;

int n, b[100000], ans = INF;

void dfs(int val, int idx, int cnt, int r) { // 이전에 선택한 값, 인덱스, 연산 횟수, 공차
	if (cnt >= ans) return;
	if (idx >= n) {
		ans = min(cnt, ans);
		return;
	}
	if(b[idx] - val == r) dfs(b[idx], idx + 1, cnt, r);
	if(b[idx] - 1 - val == r) dfs(b[idx] - 1, idx + 1, cnt + 1, r);
	if(b[idx] + 1 - val == r) dfs(b[idx] + 1, idx + 1, cnt + 1, r);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &b[i]);
	for (int i = -1; i < 2; i++)
		for (int j = -1; j < 2; j++)
			dfs(b[1] + i, 2, (i != 0) + (j != 0), (b[1] + i) - (b[0] + j));
	printf("%d", ans != INF ? ans : -1);
}

/*
먼저 첫 번째 항과 두 번째 항에 연산을 수행했을 때, 나올 수 있는 모든 공차와 두 번째 항의 초깃값을 구해줍니다.

각 항은 +1, -1, 0을 더해주는 세 가지 연산이 가능하므로 3 * 3 = 9가지의 경우가 나오게 됩니다.

각각의 경우의 공차와 두 번째 항의 초깃값을 이용해서, 남은 수들에 연산을 수행했을 때 등차수열을 만들 수 있는지 확인해줍니다.
*/