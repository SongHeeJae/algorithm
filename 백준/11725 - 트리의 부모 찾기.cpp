#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& graph, vector<bool>& visited, vector<int>& parent, int c) {
	visited[c] = true;
	for(int i=0; i<graph[c].size(); i++)
		if (!visited[graph[c][i]]) {
			parent[graph[c][i]] = c;
			dfs(graph, visited, parent, graph[c][i]);
		}
}

int main()
{
	int n, a, b;
	scanf("%d", &n);
	vector<vector<int>> graph(n + 1, vector<int>());
	vector<bool> visited(n + 1, false);
	vector<int> parent(n + 1);
	while (--n) {
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);		
	}

	dfs(graph, visited, parent, 1);

	for (int i = 2; i < parent.size(); i++) printf("%d\n", parent[i]);
}