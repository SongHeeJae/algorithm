#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, a, b;
vector<int> graph[100001];
int p[100001][17]; // p[i][j] = i번 노드의 2^j번 조상 노드
int d[100001]; // d[i] = i번 노드의 깊이

void init(int node, int depth) {
	d[node] = depth;
	for (int i = 0; i < graph[node].size(); i++) {
		if (d[graph[node][i]] != -1) continue;
		p[graph[node][i]][0] = node;
		init(graph[node][i], depth + 1);
	}
}

int lca() {
	if (d[a] > d[b]) swap(a, b); // b가 더 깊도록 스왑
	int diff = d[b] - d[a]; // b의 깊이를 a의 깊이까지 올려줌
	for (int i = 0; diff != 0; i++) {
		if (diff & 1) {
			b = p[b][i];
		}
		diff >>= 1;
	}
	if (a == b) return a;
	for (int i = 16; i >= 0; i--) {
		if (p[a][i] != p[b][i]) {
			a = p[a][i];
			b = p[b][i];
		}
	}
	return p[a][0];
}

int main() {
	memset(d, -1, sizeof(d));
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	init(1, 0);

	for (int i = 1; i < 17; i++) {
		for (int j = 1; j <= n; j++) {
			p[j][i] = p[p[j][i - 1]][i - 1];
		}
	}

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", lca());
	}
}

/*
i번 노드의 2^j번째 조상 노드를 기억하여, 가장 가까운 공통 조상노드를 찾아주었습니다.
*/