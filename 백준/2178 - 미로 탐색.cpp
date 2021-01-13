#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[] = {-1, 0, 0, 1};
int dy[] = { 0, 1, -1, 0 }; // 상하좌우

void bfs(vector<vector<int>>& map, vector<vector<bool>>& check, int n, int m) {
	queue<pair<int, int>> q;
	int c = 0;
	q.push(make_pair(0, 0));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx >= 0 && yy >= 0 && xx < n && yy < m) {
				if (map[xx][yy] > 0 && !check[xx][yy]) {
					check[xx][yy] = true;
					map[xx][yy] += map[x][y];
					q.push(make_pair(xx, yy));
				}
			}
			
		}
	}
}

int main() {
 
	int n, m;
	scanf("%d %d", &n, &m);
	vector<vector<int>> map(n, vector<int>(m));
	vector<vector<bool>> check(n, vector<bool>(m, 0));
	getchar();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			map[i][j] = getchar() - '0';
		getchar();
	}

	bfs(map, check, n, m);
	printf("%d\n", map[n - 1][m - 1]);
}
