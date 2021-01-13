#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

void citybus(vector<vector<pair<int, int>>>& graph, int s, int e) {
	vector<int> d(graph.size(), INF);
	d[s] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, s});
	while (!pq.empty()) {
		int cost = pq.top().first;
		int vertex = pq.top().second;
		pq.pop();
		if (d[vertex] < cost) continue;

		for (int i = 0; i < graph[vertex].size(); i++) {
			int nextCost = graph[vertex][i].second + d[vertex];
			int nextVertex = graph[vertex][i].first;

			if (d[nextVertex] > nextCost) {
				d[nextVertex] = nextCost;
				pq.push({ nextCost, nextVertex });
			}
		}
	}
	printf("%d\n", d[e]);
}

int main()
{
	int n, m, a, b, c, s, e;
	scanf("%d %d", &n, &m);
	vector<vector<pair<int, int>>> graph(n + 1, vector<pair<int, int>>());
	while (m--) {
		scanf("%d %d %d", &a, &b, &c);
		graph[a].push_back({ b, c });
	}
	scanf("%d %d", &s, &e);
	citybus(graph, s, e);
}