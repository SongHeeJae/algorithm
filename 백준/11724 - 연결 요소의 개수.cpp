#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(vector<vector<int>>& graph, vector<bool>& visited, int c) {
	visited[c] = true;
	for (int i = 0; i < graph[c].size(); i++)
		if (!visited[graph[c][i]]) dfs(graph, visited, graph[c][i]);
}

int main()
{
	int n, m, a, b, c = 0;
	scanf("%d %d", &n, &m);
	vector<vector<int>> graph(n + 1, vector<int>());
	vector<bool> visited(n + 1, false);
	while (m--) {
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
		if (!visited[i]) {
			dfs(graph, visited, i);
			c++;
		}
	printf("%d\n", c);
}