#include <iostream>
#include <queue>
using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int n, m, hx, hy, ex, ey;
int map[1000][1000];
bool visit[1000][1000][2] = { false };

int main() {
	scanf("%d %d %d %d %d %d", &n, &m, &hx, &hy, &ex, &ey);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &map[i][j]);

	queue<vector<int>> q;
	q.push({ hx - 1, hy - 1, 0, 0 });
	visit[hx - 1][hy - 1][0] = true;
	while (!q.empty()) {
		int x = q.front()[0];
		int y = q.front()[1];
		int t = q.front()[2];
		int c = q.front()[3];
		q.pop();
		if (x == ex - 1 && y == ey - 1) {
			printf("%d", c);
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (map[nx][ny] == 1) {
				if (visit[nx][ny][1] || t != 0) continue;
				q.push({ nx, ny, 1, c + 1 });
				visit[nx][ny][1] = true;
			}
			else {
				if (visit[nx][ny][t]) continue;
				q.push({ nx, ny, t, c + 1 });
				visit[nx][ny][t] = true;
			}
		}
	}
	printf("-1");
}

/*
BFS를 이용하여 풀었습니다.
다음으로 이동할 위치가 빈 칸이라면, 그냥 이동하면 됩니다.
다음으로 이동할 위치가 벽이라면, 아직 지팡이를 사용하지 않았을 때는 지팡이를 사용해서 이동할 수 있습니다.
지팡이를 이미 사용했다면 이동할 수 없습니다.
큐에 지팡이 사용 여부를 같이 기억해주고, 지팡이를 사용했을 때와 사용하지 않았을 때의 방문 처리를 별도로 해주었습니다.
*/