#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };
bool alp[26] = { false, };
int ans = -1;

void dfs(vector<vector<char>>& map, int x, int y, int d) {
	alp[map[x][y] - 'A'] = true;
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx >= 0 && yy >= 0 && xx < map.size()
			&& yy < map[0].size() && !alp[map[xx][yy] - 'A']) {
			dfs(map, xx, yy, d + 1);
			alp[map[xx][yy] - 'A'] = false;
		}
	}
	ans = max(d, ans);
}

int main()
{
	int r, c;
	scanf("%d %d", &r, &c);
	vector<vector<char>> map(r, vector<char>(c));
	vector<vector<bool>> visited(r, vector<bool>(c, false));
	getchar();
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) map[i][j] = getchar();
		getchar();
	}
	dfs(map, 0, 0, 1);
	printf("%d\n", ans);
}