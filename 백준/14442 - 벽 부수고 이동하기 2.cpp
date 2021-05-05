#include <iostream>
#include <queue>
using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int n, m, k;
char map[1000][1001];
bool visit[1000][1000][10] = { false };

queue<vector<int>> q;

int bfs() {
	q.push({ 0, 0, 1, 0 });
	visit[0][0][0] = true;
	while (!q.empty()) {
		int x = q.front()[0];
		int y = q.front()[1];
		int t = q.front()[2];
		int d = q.front()[3];
		q.pop();
		if (x == n - 1 && y == m - 1) return t;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (map[nx][ny] == '1') {
				if (d < k) {
					if (visit[nx][ny][d + 1]) continue;
					q.push({ nx, ny, t + 1, d + 1 });
					visit[nx][ny][d + 1] = true;
				}
			}
			else {
				if (visit[nx][ny][d]) continue;
				q.push({ nx, ny, t + 1, d });
				visit[nx][ny][d] = true;
			}
		}
	}
	return -1;
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++)
		scanf("%s", map[i]);
	printf("%d", bfs());
}

/*
visit[방문지점 x좌표][방문지점 y좌표][벽을 부순 갯수]를 가지고 BFS를 수행해주었습니다.
*/