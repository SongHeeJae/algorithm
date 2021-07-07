#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, a, p[1000];
long long ans = 0;
vector<vector<int>> edges;

int findParent(int x) {
	if (p[x] == x) return x;
	else return p[x] = findParent(p[x]);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		p[i] = i;
		for (int j = 0; j <= i; j++) scanf("%d", &a);
		for (int j = i + 1; j < n; j++) {
			scanf("%d", &a);
			edges.push_back({ a, i, j });
		}
	}
	sort(edges.begin(), edges.end());
	int cnt = 0;
	for (int i = 0; i < edges.size(); i++) {
		int pa = findParent(edges[i][1]);
		int pb = findParent(edges[i][2]);
		if (pa != pb) {
			p[pa] = pb;
			ans += edges[i][0];
			if (++cnt == n - 1) break;
		}
	}
	printf("%lld", ans);
}

/*
주어진 각 행성 간의 플로우 관리 비용으로 간선들을 만든 뒤,
크루스칼 알고리즘을 수행하며 최소 유지비용을 구해주었습니다.
*/