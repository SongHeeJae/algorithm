#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int t, n, a, b;
int p[10001];
int d[10001];
vector<vector<int>> graph;

int getParent(int x) {
	if (p[x] == 0) return x;
	else return getParent(p[x]);
}

void dfs(int node, int depth) {
	d[node] = depth;
	for (int i = 0; i < graph[node].size(); i++) {
		dfs(graph[node][i], depth + 1);
	}
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);

		memset(p, 0, sizeof(p));
		graph.clear();
		graph.resize(n + 1);

		for (int i = 1; i < n; i++) {
			scanf("%d %d", &a, &b);
			p[b] = a;
			graph[a].push_back(b);
		}
		scanf("%d %d", &a, &b);

		int root = getParent(1);
		dfs(root, 0);
		while (d[a] != d[b]) {
			if (d[a] > d[b]) a = p[a];
			else b = p[b];
		}
		while (a != b) {
			a = p[a];
			b = p[b];
		}
		printf("%d\n", a);
	}
}

/*
각 노드의 깊이를 구해둔 뒤, 입력 받은 두 노드 중 더 깊은 노드를 부모 노드로 올려서 같은 깊이로 맞춰줍니다.
같은 노드가 나올 때까지 부모 노드로 올려줍니다.
*/