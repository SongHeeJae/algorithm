#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue<pair<int, int>> pq;

int dfs(vector<vector<int>>& graph, vector<bool>& visited, int n) {
	int c = 1;
	visited[n] = true;
	for (int i = 0; i < graph[n].size(); i++)
		if (!visited[graph[n][i]]) c += dfs(graph, visited, graph[n][i]);
	return c;
}

void f(vector<vector<int>>& graph, int n) {
	vector<bool> visited(graph.size(), false);
	pq.push({ dfs(graph, visited, n), n});
}

int main() {
	int n, m, a, b;
	scanf("%d %d", &n, &m);
	vector<vector<int>> graph(n + 1, vector<int>());
	while (m-- && scanf("%d %d", &a, &b))  graph[b].push_back(a);
	for (int i = 1; i <= n; i++) f(graph, i);
	vector<int> ans;
	int prev = pq.top().first;
	ans.push_back(pq.top().second);
	pq.pop();
	while (!pq.empty()) {
		if (prev != pq.top().first) break;
		ans.push_back(pq.top().second);
		prev = pq.top().first;
		pq.pop();
	}
	sort(ans.begin(), ans.end());
	for (int i : ans) printf("%d ", i);
}
