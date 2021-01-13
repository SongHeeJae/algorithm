#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };

int main() {
	int n, m, x, y, c, ans = -1;
	scanf("%d %d", &n, &m);
	vector<vector<int>> map(n, vector<int>(m));
	vector<vector<vector<int>>> visited(2, vector<vector<int>>(n, vector<int>(m, 0)));
	getchar();
	for (int i = 0; i < n; i++, getchar()) {
		for (int j = 0; j < m; j++)
			map[i][j] = getchar() - '0';
	}
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(0, 0, 0));
	visited[0][0][0] = 1;
	while (!q.empty()) {
		tie(x, y, c) = q.front();
		if (x == n - 1 && y == m - 1) {
			ans = visited[c][x][y]; // bfs 먼저 도착
			break;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx>=0 && yy>=0 && xx < n && yy < m && !visited[c][xx][yy]) {
				if (!map[xx][yy]) { // 이동 가능
					// 현재 벽 상태 유지하며 이동
					visited[c][xx][yy] = visited[c][x][y] + 1;
					q.push(make_tuple(xx, yy, c));
				}
				else if (map[xx][yy] && c == 0) { // 이동불가능한데 아직 벽 안뚫었을때
					q.push(make_tuple(xx, yy, 1)); // 벽 뚫은 상태 넣어줌
					// 벽뚫고 방문
					visited[1][xx][yy] = visited[c][x][y] + 1;
				}
				
			}
		}
	}
	printf("%d\n", ans);
}
