#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, a, b, c, p[100001] = { 0 };
long long s = 0;
vector<pair<int, pair<int, int>>> edges;

int findParent(int x) {
	if (p[x] == 0) return x;
	else return p[x] = findParent(p[x]);
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		edges.push_back({ c, {a, b} });
		s += c;
	}
	sort(edges.begin(), edges.end());
	int cnt = 0;
	for (int i = 0; i < edges.size(); i++) {
		int pa = findParent(edges[i].second.first);
		int pb = findParent(edges[i].second.second);
		if (pa == pb) continue;
		p[pa] = pb;
		s -= edges[i].first;
		if (++cnt == n - 1) {
			printf("%lld", s);
			return 0;
		}
	}
	printf("-1");
}

/*
크루스칼 알고리즘으로 모든 도시를 연결해주는 최소 비용을 구하여 절약 비용을 구해주었습니다.
*/