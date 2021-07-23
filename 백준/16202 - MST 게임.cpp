#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<pair<int, pair<int, int>>> edges; // {cost, {vertex, vertex}}
int n, m, k, x, y, p[1001];
bool del[10000] = { false };

int findParent(int x) {
	if (p[x] == 0) return x;
	else return p[x] = findParent(p[x]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y;
		edges.push_back({ i, {x, y} });
	}

	while (k--) {
		memset(p, 0, sizeof(p));
		int cost = 0, cnt = 0;
		for (int i = 0; i < m; i++) {
			if (del[i]) continue;
			int pa = findParent(edges[i].second.first);
			int pb = findParent(edges[i].second.second);
			if (pa != pb) {
				if (!cnt) del[i] = true;
				p[pa] = pb;
				cost += edges[i].first;
				if (++cnt == n - 1) break;
			}
		}
		if (cnt == n - 1) cout << cost << " ";
		else {
			while (k-- >= 0) cout << "0 ";
			break;
		}
	}
}

/*
주어진 간선의 가중치는 오름차순으로 정렬되어있습니다.
각 턴마다 크루스칼을 수행하여 점수를 구해준 뒤, MST에 포함된 간선 중 가장 처음에 선택된 간선을 제거해주었습니다.
*/