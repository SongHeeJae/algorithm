#include <iostream>
#include <vector>
using namespace std;

int ans = 0;

void dfs1(vector<vector<int>>& tree, vector<bool>& visited, int a) {
	visited[a] = true;
	for (int i = 0; i < tree[a].size(); i++)
		if (!visited[tree[a][i]])
			dfs1(tree, visited, tree[a][i]);
	tree[a].clear();
}

void dfs2(vector<vector<int>>& tree, vector<bool>& visited, int r, int a) {
	visited[r] = true;
	bool f = true;
	for (int i = 0; i < tree[r].size(); i++) {
		if (!visited[tree[r][i]] && tree[r][i] != a) {
			dfs2(tree, visited, tree[r][i], a);
			f = false;
		}
	}
	if (f) ans++;
	visited[r] = false;
}

int main()
{
	int n, a, r = 0;
	scanf("%d", &n);
	vector<vector<int>> tree(n, vector<int>());
	for (int i = 0; i < n && scanf("%d", &a); i++) {
		if (a == -1) r = i;
		else tree[a].push_back(i);
	}
	scanf("%d", &a);
	if (r == a) printf("0");
	else {
		vector<bool> visited(n, false);
		dfs1(tree, visited, a);
		dfs2(tree, visited, r, a);
		printf("%d", ans);
	}
}