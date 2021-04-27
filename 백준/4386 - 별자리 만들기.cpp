#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int p[100], n;
double a, b, ans = 0;
vector<pair<double, double>> stars;
vector<pair<double, pair<int, int>>> edges;

double getDist(double x1, double y1, double x2, double y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int findParent(int x) {
	if (p[x] == x) return x;
	else return p[x] = findParent(p[x]);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lf %lf", &a, &b);
		stars.push_back({ a, b });
		p[i] = i;
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			edges.push_back({getDist(stars[i].first, stars[i].second, stars[j].first, stars[j].second),{i, j} });
		}
	}
	sort(edges.begin(), edges.end());
	for (int i = 0; i < edges.size(); i++) {
		int pa = findParent(edges[i].second.first);
		int pb = findParent(edges[i].second.second);
		if (pa != pb) {
			ans += edges[i].first;
			p[pa] = pb;
		}
	}
	printf("%.2lf", ans);
}

/*
각 별 사이의 거리를 구하여 모든 간선을 만들어줍니다.
간선을 거리 오름차순으로 정렬한 뒤, 최소 거리부터 사이클을 만들지 않으며 같은 별자리로 묶어줍니다.
*/