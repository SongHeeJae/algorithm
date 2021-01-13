#include <iostream>
#include <queue>
using namespace std;

int n, m, T;
int map[100][100];
bool visit[2][100][100];
int dx[] = { -1,1,0,0 };
int dy[] = { 0, 0, -1, 1 };

void bfs() {
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {0, 0}, {0, 0} });
	visit[0][0][0] = true;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int t = q.front().second.first;
		int s = q.front().second.second;
		q.pop();

		if (t > T) {
			printf("Fail");
			return;
		}
		if (x == n - 1 && y == m - 1) {
			printf("%d", t);
			return;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (visit[s][nx][ny]) continue;
			if (!s && map[nx][ny] == 1) continue;
			visit[s][nx][ny] = true;
			if (map[nx][ny] == 2) {
				visit[1][nx][ny] = true; // 방금 지나온 위치
				q.push({ {nx, ny}, {t + 1, 1} });
			}
			else {
				q.push({ {nx, ny}, {t + 1, s} });
			}
			
		}
	}
	printf("Fail");
}
int main() {
	scanf("%d %d %d", &n, &m, &T);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &map[i][j]);
	bfs();
}

/*
bfs를 이용하여 구현하였습니다. "그람"을 습득했을 때와 습득하지 않았을 때의 visit를 별도로 분리하였습니다.
*/