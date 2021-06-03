#include <iostream>
#include <vector>
using namespace std;

int n, m, a, b, v = 1, ans = 0;
vector<int> graph[501];
int visit[501] = { 0 };
int cnt[501] = { 0 };

int dfs(int node) {
	int c = 1;
	visit[node] = v;
	cnt[node]++;
	for (int i = 0; i < graph[node].size(); i++) {
		if (visit[graph[node][i]] == v) continue;
		c += dfs(graph[node][i]);
	}
	return c;
}

int main() {
	scanf("%d %d", &n, &m);
	while (m-- && scanf("%d %d", &a, &b)) graph[a].push_back(b);
	for (int i = 1; i <= n; i++) cnt[i] += dfs(i), v++;
	for (int i = 1; i <= n; i++)
		if (cnt[i] == n + 1) ans++;
	printf("%d", ans);
}

/*
먼저, 주어진 키 순서를 그래프 형태로 만들어줍니다.
각 노드에서 시작하는 DFS를 돌면서,
각 노드가 자식 노드를 방문하는 횟수(어떤 노드로 도착할 수 있는 부모 노드의 개수), 각 노드에서 이동할 수 있는 자식 노드의 개수를 업데이트해줍니다.
즉, 자신으로 올 수 있는 부모 노드의 개수 + 자신에서 갈 수 있는 자식 노드의 개수가 (n - 1)개라면,
자신을 제외한 나머지의 순위는 정확히 모르더라도 자신의 순위는 정할 수 있습니다.
*/