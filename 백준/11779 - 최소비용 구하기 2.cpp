#include <iostream>
#include <queue>
#include <vector>
#define INF 2147483647
using namespace std;

int n, m, a, b, c;
vector<pair<int, int>> graph[1001];

void dijkstra(int start, int end) {
	vector<int> dist(1001, INF);
	priority_queue<pair<int, int>> pq;
	vector<int> prev(1001, INF);
	vector<int> path;
	dist[start] = 0;
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
				pq.push({ -nextCost, nextNode });
				prev[nextNode] = node;
				dist[nextNode] = nextCost;
			}
		}
	}
	printf("%d\n", dist[end]);
	for (int i = end; i != INF; i = prev[i])
		path.push_back(i);
	printf("%d\n", path.size());
	for (int i = path.size() - 1; i >= 0; i--)
		printf("%d ", path[i]);
}

int main() {
	scanf("%d %d", &n, &m);
	while (m--) {
		scanf("%d %d %d", &a, &b, &c);
		graph[a].push_back({ b, c });
	}
	scanf("%d %d", &a, &b);
	dijkstra(a, b);
}

/*
다익스트라 알고리즘을 이용해서 시작점부터 도착점까지의 최소 비용과 경로를 구해주었습니다.
*/