#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

double ans = 0;
int n, m, a, b, p[1000];
vector<pair<int, int>> pos;
vector<pair<double, pair<int, int>>> edges;

double getDist(long long x1, long long y1, long long x2, long long y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int findParent(int x) {
	if (p[x] == x) return x;
	else return p[x] = findParent(p[x]);
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		p[i] = i;
		scanf("%d %d", &a, &b);
		pos.push_back({ a, b });
	}

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		int pa = findParent(a - 1);
		int pb = findParent(b - 1);
		p[pa] = pb;
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (i == j) continue;
			edges.push_back({ getDist(pos[i].first, pos[i].second, pos[j].first, pos[j].second), {i, j} });
		}
	}
	sort(edges.begin(), edges.end());
	for (int i = 0; i < edges.size(); i++) {
		int pa = findParent(edges[i].second.first);
		int pb = findParent(edges[i].second.second);
		if (pa != pb) {
			p[pa] = pb;
			ans += edges[i].first;
		}
	}
	printf("%.2lf", ans);
}

/*
주어진 통로를 통해 이미 연결된 신들을 같은 집합으로 묶어줍니다.
그 후, 각 우주신들 사이의 거리를 계산하여 간선들을 구해줍니다.
간선을 오름차순으로 정렬한 뒤, 아직 연결되지 않은 신이라면 같은 집합으로 묶어줍니다. 
*/