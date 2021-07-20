#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
vector<pair<int, int>> graph[100001];
int p[100001][17]; // p[i][j] = i번 노드의 2^j번 조상 노드
int minDist[100001][17]; // xxxDist[i][j] = i번 노드의 2 ^ j번 
int maxDist[100001][17]; // 조상 노드까지 가장 (짧은, 긴) 도로 길이
int d[100001]; // d[i] = i번 노드의 깊이

void init(int node, int depth, int val) {
	d[node] = depth;
	minDist[node][0] = val;
	maxDist[node][0] = val;
	for (pair<int,int>& edge : graph[node]) {
		int next = edge.first;
		int cost = edge.second;
		if (d[next] != -1) continue;
		p[next][0] = node;
		init(next, depth + 1, cost);
	}
}

pair<int, int> lca(int u, int v) {
	int minRes = 1e6, maxRes = 0;
	if (d[u] > d[v]) swap(u, v); // v가 더 깊도록 스왑
	int diff = d[v] - d[u]; // v의 깊이를 u의 깊이까지 올려줌
	for (int i = 0; diff != 0; i++) {
		if (diff & 1) {
			minRes = min(minRes, minDist[v][i]);
			maxRes = max(maxRes, maxDist[v][i]);
			v = p[v][i];
		}
		diff >>= 1;
	}

	if (u == v) return {minRes, maxRes};

	for (int i = 16; i >= 0; i--) {
		if (p[u][i] != p[v][i]) {
			minRes = min({ minRes, minDist[u][i], minDist[v][i] });
			maxRes = max({ maxRes, maxDist[u][i], maxDist[v][i] });
			u = p[u][i];
			v = p[v][i];
		}
	}
	return {
		min({minRes, minDist[u][0], minDist[v][0]}),
		max({maxRes, maxDist[u][0], maxDist[v][0]})
	};
}

int main() {
	int a, b, c;
	memset(d, -1, sizeof(d));

	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d %d %d", &a, &b, &c);
		graph[a].push_back({b, c});
		graph[b].push_back({a, c});
	}

	init(1, 0, 0);

	for (int i = 1; i < 17; i++) {
		for (int j = 1; j <= n; j++) {
			p[j][i] = p[p[j][i - 1]][i - 1];
			minDist[j][i] = min(minDist[j][i - 1], minDist[p[j][i - 1]][i - 1]);
			maxDist[j][i] = max(maxDist[j][i - 1], maxDist[p[j][i - 1]][i - 1]);
		}
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		pair<int, int> ans = lca(a, b);
		printf("%d %d\n", ans.first, ans.second);
	}
}

/*
N개의 도시는 N-1개의 도로로 연결되어있습니다.
즉, 사이클이 없는 그래프 형태이므로 트리 구조의 일종이라고 볼 수 있습니다.

두 도시를 연결하는 경로에서 가장 짧은 도로의 길이와 가장 긴 도로의 길이를 빠르기 구하기 위해서 LCA를 이용하였습니다.
minDist[i][j] = i번 노드의 2^j번 조상 노드까지 가장 짧은 도로 길이
maxDist[i][j] = i번 노드의 2^j번 조상 노드까지 가장 긴 도로 길이를 전처리해줍니다.

두 도시를 d, e라고 할 때,
d에서 lca(d, e)까지의 가장 짧거나 긴 도로 길이,
e에서 lca(d, e)까지의 가장 짧거나 긴 도로 길이를 구해줄 것입니다.

d와 e 중에서 더 깊은 노드를 같은 높이를 맞추는 과정, lca(d, e)까지 상위 노드로 올라오는 과정 속에서,
가장 짧거나 긴 도로의 길이를 계속해서 업데이트해줍니다.
*/