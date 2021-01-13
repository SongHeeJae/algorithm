#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int ans = -1;
void dfs(vector<vector<int>>& map, vector<vector<bool>>& visited, int x, int y, int d, int s) {
	if (d == 3) {
		ans = max(ans, s);
		return;
	}
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx >= 0 && yy >= 0 && xx < map.size() && yy < map[0].size() && !visited[xx][yy]) {
			dfs(map, visited, xx, yy, d + 1, s + map[xx][yy]);
			visited[xx][yy] = false;
		}
	}
}

void anotherShape(vector<vector<int>>& map, int x, int y) {
	int n = map.size();
	int m = map[0].size();
	if (x + 1 < n && y + 2 < m)
		ans = max(ans, map[x][y] + map[x][y + 1] + map[x][y + 2] + map[x + 1][y + 1]);
	if (x + 2 < n && y - 1 >= 0)
		ans = max(ans, map[x][y] + map[x + 1][y] + map[x + 2][y] + map[x + 1][y - 1]);
	if (x + 1 < n && y - 1 >= 0 && y + 1 < m) 
		ans = max(ans, map[x][y] + map[x + 1][y] + map[x + 1][y - 1] + map[x + 1][y + 1]);
	if (x + 2 < n && y + 1 < m)
		ans = max(ans, map[x][y] + map[x + 1][y] + map[x + 2][y] + map[x + 1][y + 1]);
}


int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	vector<vector<int>> map(n, vector<int>(m));
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &map[i][j]);
	for(int i=0; i<n; i++)
		for (int j = 0; j < m; j++) {
			dfs(map, visited, i, j, 0, map[i][j]);
			anotherShape(map, i, j);
			visited[i][j] = false;
		}
	printf("%d\n", ans);
}