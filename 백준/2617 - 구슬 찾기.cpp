#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<vector<int>> graph1(100, vector<int>());
vector<vector<int>> graph2(100, vector<int>());
int n, m, a, b, c = 0, mid, c1, c2;
bool visited1[100] = { false, };
bool visited2[100] = { false, };

void dfs1(int node) {
	visited1[node] = true;
	for (int i = 0; i < graph1[node].size(); i++) {
		if (!visited1[graph1[node][i]]) {
			c1++;
			dfs1(graph1[node][i]);
		}
	}
}

void dfs2(int node) {
	visited2[node] = true;
	for (int i = 0; i < graph2[node].size(); i++) {
		if (!visited2[graph2[node][i]]) {
			c2++;
			dfs2(graph2[node][i]);
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	while (m--) {
		scanf("%d %d", &a, &b);
		graph1[a].push_back(b);
		graph2[b].push_back(a);
	}
	mid = n / 2 + 1;
	for (int i = 1; i <= n; i++) {
		c1 = c2 = 0;
		memset(visited1, false, sizeof(visited1));
		memset(visited2, false, sizeof(visited2));
		dfs1(i);
		dfs2(i);
		if (c1 >= mid || c2 >= mid) c++;
	}
	printf("%d", c);
}