#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int n, m;
int p[1001] = { 0 };
vector<piii> edges;

int findParent(int x) {
	if (p[x] == 0) return x;
	else return p[x] = findParent(p[x]);
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		edges.push_back({ c, {a, b} });
	}

	sort(edges.begin(), edges.end());

	int cnt = 0;
	int totalMinimumCost = 0;
	for (auto& edge : edges) {
		int cost = edge.first;
		int cur = edge.second.first;
		int nxt = edge.second.second;
		int pcur = findParent(cur);
		int pnxt = findParent(nxt);

		if (pcur == pnxt) continue;

		p[pcur] = nxt;
		totalMinimumCost += cost;
		if (++cnt == n - 1) break;
	}
	printf("%d", totalMinimumCost);
}

/*
크루스칼 알고리즘으로 모든 노드를 연결하였습니다.
*/