#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

vector<vector<int>> edges;
unordered_set<int> work;

int n, m, s, a, b;
long long k;
int p[1000001];

int findParent(int x) {
	if (p[x] == x) return x;
	else return p[x] = findParent(p[x]);
}

int main() {
	scanf("%d %d %lld", &n, &m, &k);
	if (m <= 1) {
		printf("YES");
		return 0;
	}
	p[0] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &s);
		edges.push_back({ s, 0, i });
		p[i] = i;
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		work.insert(a * b);
	}
	if (work.find(n) == work.end()) edges.push_back({ 0, 1, n });
	for (int i = 1; i <= n - 1; i++) {
		if (work.find(i * (i + 1)) == work.end()) {
			edges.push_back({ 0, i, i + 1 }); // 강의실 간에 가중치는 0
		}
	}
	sort(edges.begin(), edges.end());
	int cnt = 0;
	for (int i = 0; i < edges.size(); i++) {
		int pa = findParent(edges[i][1]);
		int pb = findParent(edges[i][2]);
		if (pa != pb) {
			p[pa] = pb;
			k -= edges[i][0];
			if (++cnt == n) break;
		}
	}
	printf("%s", k >= 0 ? "YES" : "NO");
}

/*
각 강의실을 1 ~ N번 노드, 와우도를 0번 노드로 가정한 뒤,
공사 중인 곳을 제외한 모든 간선을 구해주었습니다.
구해진 간선으로 최소 스패닝 트리를 구한 후, K개의 돌로 이 트리를 구성할 수 있는지 확인하였습니다.
*/