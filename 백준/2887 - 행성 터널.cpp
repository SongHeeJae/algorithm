#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int p[100000], n, x, y, z, idx;
vector<vector<int>> planet;
vector<pair<int, pair<int, int>>> edges;

bool comp(vector<int>& a, vector<int>& b) {
	return a[idx] < b[idx];
}

int getCost(vector<int>& a, vector<int>& b) {
	return min({abs(a[0]-b[0]), abs(a[1]-b[1]), abs(a[2]-b[2])});
}

int findParent(int x) {
	if (p[x] == x) return x;
	else return p[x] = findParent(p[x]);
}

int getMinimumCost() {
	int cost = 0;
	for (int i = 0; i < edges.size(); i++) {
		int pa = findParent(edges[i].second.first);
		int pb = findParent(edges[i].second.second);
		if (pa != pb) {
			cost += edges[i].first;
			p[pa] = pb;
		}
	}
	return cost;
}

void initEdges() {
	for (idx = 0; idx < 3; idx++) {
		sort(planet.begin(), planet.end(), comp);
		for (int j = 1; j < n; j++)
			edges.push_back({ getCost(planet[j - 1], planet[j]), { planet[j - 1][3], planet[j][3]} });
	}
	sort(edges.begin(), edges.end());
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &x, &y, &z);
		planet.push_back({ x, y, z, i });
		p[i] = i;
	}
	initEdges();
	printf("%d", getMinimumCost());
}

/*
행성 사이의 간선을 구하여 최소 비용을 구해줍니다.
하지만 행성의 개수가 N개이므로,  모든 간선을 구하면 메모리 초과 또는 시간초과가 나게 됩니다.
두 행성을 연결할 때 드는 비용은 각 차원 좌표 차의 절댓값 중 최솟값입니다.
따라서 최소 비용으로 연결할 수 있는 간선의 후보는, 각 좌표 기준으로 정렬했을 때, 그 좌표의 거리가 인접한 행성입니다.
예를 들어,
5
11 -15 -15
14 -5 -15
-1 -1 -5
10 -4 -1
19 -4 19
에서 x 좌표로 정렬하면,
x좌표값은 -1, 10, 11, 14, 19가 됩니다.
x좌표가 -1인 행성은 10인 행성과 연결했을 때, 11의 비용을 가지게 됩니다.
-1인 행성은 10인 행성과 연결했을 때 이미 최소 비용으로 연결될 수 있으므로, 다른 행성과 연결한들 의미가 없으므로 간선의 후보에 들어가지 못합니다.
각각의 좌표값에 대해서 정렬 후, 인접한 행성과의 거리로 간선의 후보를 구해주면 됩니다. 
*/