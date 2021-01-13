#include <iostream>
#include <vector>
using namespace std;

int dfs(vector<vector<int>>& c, vector<bool>& visited, int pos) {
	int ans = 1;
	for (int i = 0; i < c[pos].size(); i++) {
		int p = c[pos][i];
		if (!visited[p]) {
			visited[p] = true;
			ans += dfs(c, visited, p);
		}
	}
	return ans;
}

int main() {
 
	int n, m, a, b;
	scanf("%d %d", &n, &m);
	vector<vector<int>> c(n + 1, vector<int>());
	vector<bool> visited(n + 1, false);
	while (m--) {
		scanf("%d %d", &a, &b);
		c[a].push_back(b);
		c[b].push_back(a);
	}

	visited[1] = true;
	printf("%d\n", dfs(c, visited, 1) - 1);
}
