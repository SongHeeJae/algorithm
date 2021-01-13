#include <iostream>
#include <vector>
using std::vector;
int n, m, a, b;
vector<vector<int>> f(2000, vector<int>());
bool v[2000] = { false, };
void dfs(int x, int c) {
	if (c == 4) {
		printf("1");
		exit(0);
	}
	v[x] = true;
	for (int i = 0; i < f[x].size(); i++)
		if (!v[f[x][i]]) dfs(f[x][i], c + 1);
	v[x] = false;
}
int main() {
	scanf("%d %d", &n, &m);
	while (m-- && scanf("%d %d", &a, &b)) {
		f[a].push_back(b);
		f[b].push_back(a);
	}
	for (int i = 0; i < n; i++)
		dfs(i, 0);
	printf("0");
}