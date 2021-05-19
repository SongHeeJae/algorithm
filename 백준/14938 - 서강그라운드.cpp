#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 2147483647
using namespace std;

int n, m, r, ans = 0, a, b, l, t[101];
vector<pair<int, int>> graph[101];

vector<int> dijkstra(int start) {
	priority_queue<pair<int, int>> pq;
	vector<int> dist(n + 1, INF);
	dist[start] = 0;
	pq.push({ 0, start });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int node = pq.top().second;
		pq.pop();
		if (dist[node] < cost) continue;
		for (int i = 0; i < graph[node].size(); i++) {
			int nextNode = graph[node][i].first;
			int nextCost = graph[node][i].second + cost;
			if (nextCost < dist[nextNode]) {
				dist[nextNode] = nextCost;
				pq.push({ -nextCost, nextNode });
			}
		}
	}
	return dist;
}

int main() {
	scanf("%d %d %d", &n, &m, &r);
	for (int i = 1; i <= n; i++)
		scanf("%d", &t[i]);
	
	for (int i = 0; i < r; i++) {
		scanf("%d %d %d", &a, &b, &l);
		graph[a].push_back({ b, l });
		graph[b].push_back({ a, l });
	}

	for (int i = 1; i <= n; i++) {
		int sum = 0;
		vector<int> d = dijkstra(i);
		for (int j = 1; j <= n; j++)
			if (d[j] <= m) sum += t[j];
		ans = max(ans, sum);
	}
	printf("%d", ans);
}

/*
모든 지역에 대해서 각 지역을 시작점으로 했을 때의 다익스트라를 수행해줍니다.

각 지역마다 구해진 다른 지역까지의 최단 거리를 이용해서 얻을 수 있는 아이템 갯수를 파악해준 뒤,

각 지역을 시작점으로 했을 때의 가장 많이 얻을 수 있었던 아이템 갯수를 구해줍니다.
*/