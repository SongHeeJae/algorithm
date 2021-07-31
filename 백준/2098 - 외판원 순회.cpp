#include <iostream>
#include <algorithm>
#define INF 1e8
using namespace std;

int n, w[16][16], dp[16][1 << 16] = { 0 };

int dfs(int node, int v, int d) {
	if (d == n) { // 최종 도시 도착
		if (w[node][0] != 0) return w[node][0]; // 0번 도시로 돌아갈 수 있는지
		else return INF;
	}
	if (dp[node][v] != 0) return dp[node][v];
	dp[node][v] = INF;
	for (int i = 0; i < n; i++) {
		if (w[node][i] == 0 || v & (1 << i)) continue;
		dp[node][v] = min(dp[node][v], dfs(i, v | (1 << i), d + 1) + w[node][i]);
	}
	return dp[node][v];
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &w[i][j]);
		}
	}
	printf("%d", dfs(0, 1, 1));
}

/*
dp[i][j] = 현재 i번 도시에 있고, 거쳐온 도시들의 비트가 켜져있는 값이 j일 때, 앞으로 남은 도시들을 방문하는데 필요한 최소 비용을 저장해줍니다.
0번 도시에서 시작하여 각 도시들을 순회하고, 최종적으로 도착하는 도시에서 다시 0번 도시로 갈 수 있는지 검사해주었습니다.
*/