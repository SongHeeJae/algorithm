#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
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

int lca(int a, int b) {
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
	int r, a, b, ans, res;
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
		scanf("%d %d %d", &r, &a, &b);
		ans = res = lca(a, b);
		if (d[(res = lca(a, r))] > d[ans]) ans = res;
		if (d[(res = lca(b, r))] > d[ans]) ans = res;
		printf("%d\n", ans);
	}
}

/*
만약 각 루트마다 sparse table을 새로 만들어준다면, 시간 안에 모든 쿼리 결과를 구할 수 없게 됩니다.
1번 노드를 루트로 sparse table을 한 번만 만들어두면, 이를 통해 각 쿼리 결과를 구할 수 있습니다.

입력 값 r, u, v에 대하여 1번 노드가 루트인 트리와 비교했을 때, 다음과 같은 상황이 있을 수 있습니다.
1) u와 v가 루트 r의 자손 노드인 경우
 * 쿼리 결과는 lca(u, v)

2) u 또는 v 중 하나만 루트 r의 자손 노드인 경우
 * 루트의 자손인 노드를 x라고 할 때, lca(r, x)는 루트 r이 됩니다.
 * 루트의 자손이 아닌 노드를 y라고 할 때, lca(r, y)는 루트 r의 조상 노드 중 하나입니다. 
 * lca(u, v)는 루트 r의 조상 노드 중 하나입니다.
 * 따라서, 쿼리 결과는 가장 깊은 곳에 있는 루트 r입니다.

3) u와 v가 루트 r의 자손 노드가 아닌 경우
 * 쿼리 결과는 lca(r, u)와 lca(r, v) 중에서 더 깊은 곳에 있는 노드
 * 위에서 구한 두 개의 노드는 lca(u, v)보다는 더 큰 깊이를 가집니다.

따라서, lca(u, v), lca(r, u), lca(r, v) 중에서 가장 깊은 곳에 있는 노드를 구하면 됩니다. 
*/