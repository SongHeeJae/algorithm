#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>>& graph, int start) {
	vector<int> d(graph.size(), INF); // start를 기준으로 거리 비용

	d[start] = 0; // 시작위치 초기화

	// pq <자료형, 구현체, 비교연산자(greater 작은것 먼저)>
	// pair<int, int> 앞에 숫자로 비교됨 <cost, vertex>
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	// 비용 0, 시작점 시작
	pq.push(make_pair(0, start));

	while (!pq.empty()) {
		// 비용이 가장 작은 정점을 우선적으로 방문하기때문에 우선순위 큐 사용
		int cost = pq.top().first;
		int vertex = pq.top().second;
		pq.pop();

		// 최소거리만 확인. 현재 정점의 비용이 지금 경로의 비용보다 크면 continue;
		if (d[vertex] < cost) continue;

		// 현재 vertex에서 인접한 경로들 확인
		for (int i = 0; i < graph[vertex].size(); i++) {
			int nextVertex = graph[vertex][i].first;
			int nextCost = cost + graph[vertex][i].second; // 현재 비용 + 목적지의 비용
			// 현재 경로보다 더 작으면 업데이트
			if (d[nextVertex] > nextCost) {
				d[nextVertex] = nextCost;
				pq.push(make_pair(nextCost, nextVertex)); // 업데이트된 <비용, 정점> push 
			}
		}
	}

	return d;
}

int main() {

	int v, e, start, from, to, cost;
	scanf("%d %d %d", &v, &e, &start);
	vector<vector<pair<int, int>>> graph(v + 1, vector<pair<int, int>>());
	while (e--) {
		// 출발지, 목적지, 비용
		scanf("%d %d %d", &from, &to, &cost);
		graph[from].push_back(make_pair(to, cost));
	}

	vector<int> ans = dijkstra(graph, start);
	for (int i = 1; i < ans.size(); i++)
		if (ans[i] != INF) printf("%d\n", ans[i]);
		else printf("INF\n"); // 경로 없던 경우
}
