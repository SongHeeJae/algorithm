#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> edges;
int p[10001];
int v, e, a, b, c, ans = 0;

int findParent(int x) {
	if (p[x] == x) return x;
	else return p[x] = findParent(p[x]);
}

int main() {
	scanf("%d %d", &v, &e);
	for (int i = 1; i <= v; i++) p[i] = i;
	while (e--) {
		scanf("%d %d %d", &a, &b, &c);
		edges.push_back({ c, a, b });
	}
	sort(edges.begin(), edges.end());
	for (int i = 0; i < edges.size(); i++) {
		int pa = findParent(edges[i][1]);
		int pb = findParent(edges[i][2]);
		if (pa != pb) {
			p[pa] = pb;
			ans += edges[i][0];
		}
	}
	printf("%d", ans);
}

/*
간선을 가중치로 오름차순 정렬한 뒤, 사이클이 없다면 간선을 연결시켜주었습니다.
*/