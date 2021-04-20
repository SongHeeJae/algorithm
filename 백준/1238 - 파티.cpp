#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int n, m, x, a, b, c, ans = 0;
vector<pair<int, int>> graph1[10001], graph2[10001];

vector<int> dijkstra(vector<pair<int, int>> graph[], int start) {
	vector<int> dist(n + 1, INF);
	dist[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int node = pq.top().second;
		pq.pop();
		if (dist[node] < cost) continue;
		for (int i = 0; i < graph[node].size(); i++) {
			int nextNode = graph[node][i].first;
			int nextCost = cost + graph[node][i].second;
			if (nextCost < dist[nextNode]) {
				dist[nextNode] = nextCost;
				pq.push({ -nextCost, nextNode });
			}
		}
	}
	return dist;
}

int main() {
	scanf("%d %d %d", &n, &m, &x);
	while (m-- && scanf("%d %d %d", &a, &b, &c)) {
		graph1[a].push_back({ b, c });
		graph2[b].push_back({ a, c });
	}
	vector<int> dist1 = dijkstra(graph1, x);
	vector<int> dist2 = dijkstra(graph2, x);
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dist1[i] + dist2[i]);
	}
	printf("%d", ans);
}

/*
단방향 도로의 정방향과 역방향으로 두개의 그래프를 만들어줍니다.
그 후, x 지점에서 각 마을로 갈 때의 최소 비용을 각각 구해줍니다.
정방향 그래프로 구한 최소 비용 dist[i]는 x지점에서 각 마을로 갈 때의 최소 비용입니다.
역방향 그래프로 구한 최소비용 dist[i]는 각 마을에서 x지점으로 갈 때의 최소 비용입니다.
이를 이용하여 (각 마을에서 x로의 도착 비용 + x에서 각 마을로의 도착비용)의 최댓값을 구해줍니다.
*/