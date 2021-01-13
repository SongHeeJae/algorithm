#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
int n, k, a, b, x;
vector<vector<int>> graph(401, vector<int>());
bool visited[401] = { false, };
bool d[401][401] = { false, };
void bfs(int node) {
	memset(visited, false, sizeof(visited));
	queue<int> q;
	q.push(node);
	visited[node] = true;
	while (!q.empty()) {
		x = q.front();
		q.pop();
		for (int i = 0; i < graph[x].size(); i++) {
			if (!visited[graph[x][i]]) {
				visited[graph[x][i]] = true;
				d[node][graph[x][i]] = true;
				q.push(graph[x][i]);
			}
		}
	}
}
int main() {
	scanf("%d %d", &n, &k);
	while (k-- && scanf("%d %d", &a, &b)) graph[a].push_back(b);
	for (int i = 1; i <= n; i++) bfs(i);
	scanf("%d", &k);
	while (k-- && scanf("%d %d", &a, &b)) {
		if (d[a][b]) printf("-1\n");
		else if (d[b][a]) printf("1\n");
		else printf("0\n");
	}
}