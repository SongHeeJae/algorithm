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
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a);
		while (1) {
			scanf("%d", &b);
			if (b == -1) break;
			scanf("%d", &c);
			graph[a].push_back({ b, c });
		}	
	}

	mc = 1;
    // 루트에서 제일 긴거리 찾고, 그 위치에서 다시 제일 긴거리
	for (int i = 0; i < 2; i++) {
		vector<bool> visited(n + 1, false);
		m = -1;
		dfs(graph, visited, mc, 0);
	}

	printf("%d\n", m);
}