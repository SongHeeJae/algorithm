#include <iostream>
#include <vector>
using namespace std;
int c = 0;
void dfs(vector<int>& graph, vector<bool>& visit1, vector<bool>& visit2, int n) {
	visit1[n] = true;
	if (!visit1[graph[n]]) dfs(graph, visit1, visit2, graph[n]);
	else
		if (!visit2[graph[n]]) {
			for (int i = graph[n]; i != n; i = graph[i]) c++;
			c++;
		}
	visit2[n] = true;
}

int main() {
	int t, n;
	scanf("%d", &t);
	while(t--) {
		c = 0;
		scanf("%d", &n);
		vector<int> graph(n+1);
		vector<bool> visit1(n + 1, false);
		vector<bool> visit2(n + 1, false);
		for (int i = 1; i <= n; i++) scanf("%d", &graph[i]);
		for (int i = 1; i <= n; i++)
			if (!visit1[i]) dfs(graph, visit1, visit2, i);
		printf("%d\n", n-c);
	}
}
