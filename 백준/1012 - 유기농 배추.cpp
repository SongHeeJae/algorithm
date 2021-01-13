#include <iostream>
#include <vector>
using namespace std;

int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, 1, -1, 0 };

void dfs(vector<vector<int>>& map, int x, int y) {
	map[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx >= 0 && yy >= 0 &&
			xx < map.size() && yy < map[0].size() &&
			map[xx][yy] ) {
			dfs(map, xx, yy);
		}
	}
}

int main() {
	int t, m, n, k, x, y;
	scanf("%d", &t);
	while (t--) {
		int c = 0;
		scanf("%d %d %d", &m, &n, &k);
		vector<vector<int>> map(n, vector<int>(m, 0));
		while (k-- && scanf("%d %d", &x, &y)) map[y][x] = 1;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (map[i][j]) {
					c++;
					dfs(map, i, j);
				}
		printf("%d\n", c);
	}
}
