#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m, mc;
void dfs(vector<vector<pair<int, int>>>& graph, vector<bool>& visited, int c, int s) {
	visited[c] = true;
	for(int i=0; i<graph[c].size(); i++)
		if (!visited[graph[c][i].first]) {
			dfs(graph, visited, graph[c][i].first, s + graph[c][i].second);
		}
	if (s > m) {
		m = s;
		mc = c;
	}
}

int main()
{
	int n, a, b, c;
	scanf("%d", &n);
	vector<vector<pair<int, int>>> graph(n + 1, vector<pair<int, int>>());
	
	for (int i = 1; i < n; i++) {
		scanf("%d %d %d", &a, &b, &c);
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}

	mc = 1;
	for (int i = 0; i < 2; i++) {
		vector<bool> visited(n + 1, false);
		m = -1;
		dfs(graph, visited, mc, 0);
	}

	printf("%d\n", m);
}