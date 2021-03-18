#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<vector<pair<int, int>>> graph(10001, vector<pair<int, int>>());
bool visit[10001];

bool isPossible(int node, int weight, int end) {
	if (node == end) return true;
	visit[node] = true;
	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i].first;
		int w = graph[node][i].second;
		if (visit[next]) continue;
		if (w < weight) continue;
		visit[next] = true;
		if (isPossible(next, weight, end)) return true;
	}
	return false;
}

int main() {
	int n, m, a, b, c, s, e;
	scanf("%d %d", &n, &m);
	while (m--) {
		scanf("%d %d %d", &a, &b, &c);
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}
	scanf("%d %d", &s, &e);
	int l = 1, r = 1000000000;
	while (l <= r) {
		memset(visit, false, sizeof(visit));
		int mid = (l + r) / 2;
		if (isPossible(s, mid, e)) l = mid + 1;
		else r = mid - 1;
	}
	printf("%d", r);
}

/*
이분탐색을 통해 갈 수 있는 중량의 최댓값을 구해주었습니다.

(mid == 중량)의 값으로 시작 공장 지점에서 도착 공장 지점으로 갈 수 있다면 left = mid + 1,

갈 수 없다면 right = mid - 1 입니다. 
*/