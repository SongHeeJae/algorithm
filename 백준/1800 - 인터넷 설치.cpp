#include <iostream>
#include <vector>
#include <queue>
#define INF 2147483647
using namespace std;

vector<pair<int, int>> graph[1001];

int n, p, k, a, b, c;

bool dijkstra(int price) {
	vector<int> dist(n + 1, INF);
	dist[1] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, 1 });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int node = pq.top().second;
		pq.pop();
		if (dist[node] < cost) continue;
		for (int i = 0; i < graph[node].size(); i++) {
			int nextNode = graph[node][i].first;
			int nextCost = cost + (graph[node][i].second > price ? 1 : 0);
			if (dist[nextNode] > nextCost) {
				dist[nextNode] = nextCost;
				pq.push({-nextCost, nextNode});
			}
		}
	}
	return dist[n] <= k;
}

int main() {
	scanf("%d %d %d", &n, &p, &k);
	while (p--) {
		scanf("%d %d %d", &a, &b, &c);
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}
	int l = 0, r = 1e7;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (dijkstra(mid)) r = mid - 1;
		else l = mid + 1;
	}
	printf("%d", r != 1e7 ? r + 1 : -1);
}

/*
이분탐색과 다익스트라를 이용하여 풀었습니다.
mid를 최소 비용으로 할 때, 1번부터 N번까지 도달할 수 있는지를 검사해줍니다.
도달할 수 있는지의 여부를 구하기 위해 다익스트라를 수행합니다.
dist[i]는 i 지점에 도달하기 위해 필요한 mid 비용을 넘는 케이블 선의 최소 개수입니다.
dist[n]이 k개 이하라면, 1번부터 N번까지 도달할 수 있습니다.
*/