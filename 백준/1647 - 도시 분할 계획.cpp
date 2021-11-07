#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 100001
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int n, m, a, b, c;
vector<piii> edges;
int p[MAX];

int findParent(int x) {
	if (p[x] == 0) return x;
	else return p[x] = findParent(p[x]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		edges.push_back({ c, {a, b} });
	}

	sort(edges.begin(), edges.end());

	int s = 0, cnt = 0;
	for (auto& edge : edges) {
		int pa = findParent(edge.second.first);
		int pb = findParent(edge.second.second);
		if (pa != pb) {
			p[pa] = pb;
			s += edge.first;
			if (++cnt == n - 2) break;
		}
	}
	cout << s;
}

/*
최소 스패닝 트리로 모든 집을 연결하고, 여기서 가장 유지비가 비싼 길을 하나만 끊어낸다면,
마을을 두 개로 분리하면서 최소 비용으로 필요한 길만 유지할 수 있습니다.
*/