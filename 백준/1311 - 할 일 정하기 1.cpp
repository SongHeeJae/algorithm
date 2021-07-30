#include <iostream>
#include <algorithm>
#define INF 2147483647
using namespace std;

int n, d[20][20], dp[1 << 20] = { 0 };

int dfs(int idx, int v) {
	if (idx == n) return 0;
	if (dp[v] != 0) return dp[v];
	dp[v] = INF;
	for (int i = 0; i < n; i++) {
		if (v & (1 << i)) continue; // 이미 선택한 일
		dp[v] = min(dp[v], dfs(idx + 1, v | (1 << i)) + d[idx][i]);
	}
	return dp[v];
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &d[i][j]);
		}
	}
	printf("%d", dfs(0, 0));
}

/*
각 사람이 일을 선택하는 모든 순서 상황의 최솟값을 구해주었습니다.
예를 들어, 세 개의 비트가 010 이라면 첫 번째 사람이 두 번째 일을 선택한 상황입니다.
dp[i] = 비트를 나타내는 수가 i일 때(켜진 비트들은 이미 선택한 일), 남은 비트(일)들을 다 선택하는 최소 비용을 저장해줍니다. 
N의 범위는 1이상 20이하이므로, 20명의 사람이 20명의 일을 선택한 것을 표시하기 위해선 20비트가 필요합니다.   
*/