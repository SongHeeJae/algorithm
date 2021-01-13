#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m, a;
	scanf("%d %d", &n, &m);

	vector<vector<int>> map(n + 1, vector<int>(m + 1));

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m && scanf("%d", &a); j++)
			map[i][j] = a;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			map[i][j] += max(map[i][j - 1], max(map[i - 1][j - 1], map[i - 1][j]));
		
	printf("%d\n", map[n][m]);
}