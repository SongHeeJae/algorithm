#include <iostream>
#include <algorithm>
#include <cmath>
#define INF 987654321
int graph[10][10] = { 0 };
int n, num[10], a, b, sel[10], res = INF;
int selectCnt[2], selectStart[2], selectNum[2], visitCount = -1;
void dfs(int node, int s, bool* visit) {
	visit[node] = true;
	for (int i = 0; i < n; i++)
		if (graph[node][i] && !visit[i] && sel[i] == s)
			dfs(i, s, visit);
	visitCount++;
}
void select(int c) {
	if (c == n) { // 만들어진 선거구 조합
		selectCnt[0] = selectCnt[1] = selectNum[0] = selectNum[1] = 0;
		for (int i = 0; i < n; i++) {
			selectCnt[sel[i]]++;
			selectStart[sel[i]] = i;
			selectNum[sel[i]] += num[i];
		}
		for (a = 0; a < 2; a++) { // 선거구 유효한지 탐색
			bool visit[10] = { false };
			visitCount = 0;
			dfs(selectStart[a], sel[selectStart[a]], visit);
            // 조합한 선거구의 구역 개수와 방문 개수가 같은지 판별
			if (visitCount != selectCnt[a]) break;
		}
        // 유효했다면 인구 수 차의 최솟값 업데이트
		if (a == 2) res = std::min(res, abs(selectNum[0] - selectNum[1]));
		return;
	}
	for (int i = 0; i < 2; i++) {
		sel[c] = i;
		if (c == 0 && i) break; // 서로 뒤집어진 조합은 검사안함
		select(c + 1);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &num[i]);
	for (int i = 0; i < n && scanf("%d", &a); i++)
		for (int j = 0; j < a && scanf("%d", &b); j++)
			graph[i][b - 1] = graph[b - 1][i] = 1;
	select(0);
	printf("%d", res != INF ? res : -1); // 유효한 선거구가 없었다면 -1
}

/*
조합과 브루트포스를 이용하여 풀었다.

먼저 문제를 제대로 이해하지않아서 그래프 형태를 만들어내는데 어려움이 있었다.

인접 리스트로 만들다가 중복된 간선의 입력이 있다는 것을 깨닫고 인접 행렬 형태로 바꾸었다.

또, 마지막 예제 입력에서 그래프가 사이클 형태를 이룰 수도 있다는 것을 알게 되고, visit 방식을 바꾸었다. 

문제는 다음와 같은 방식으로 풀어냈다.

일단 각 구역에 대한 선거구 조합을 만들어낸다. (0 또는 1)

각 선택된 지역의 선거구가 유효한지 dfs를 돌면서 탐색한다.

유효한 선거구였다면, 두 선거구의 인구수의 차를 최솟값으로 업데이트해준다.

선거구 조합에서 "0111"과 "1000"은 동일하게 인식하기 때문에, 뒤집어진 조합에 대해선 검사를 하지 않았다.
*/