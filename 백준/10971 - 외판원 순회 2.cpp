#include <iostream>
#include <algorithm>
using namespace std;
int n, w[10][10], v[10] = { 0 }, ans = 1e7;
void dfs(int start, int node, int sum, int depth) {
	if (depth == n) {
		if(w[node][start] != 0) ans = min(ans, sum + w[node][start]); // 시작점 돌아갈 수 있으면
		return;
	}
	v[node] = true;
	for (int i = 0; i < n; i++) {
		if (w[node][i] == 0) continue;
		if (v[i]) continue;
		v[i] = 1;
		dfs(start, i, sum + w[node][i], depth + 1);
		v[i] = 0;
	}
	v[node] = false;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) scanf("%d", &w[i][j]);
	dfs(0, 0, 0, 1);
	printf("%d", ans);
}

/*
1번 도시에서 시작해서 모든 도시를 탐색하였습니다.

마지막으로 도착한 지점에서 1번 도시로 다시 돌아갈 수 있는 길이 있다면, 비용의 최솟값을 업데이트해주었습니다. 
*/