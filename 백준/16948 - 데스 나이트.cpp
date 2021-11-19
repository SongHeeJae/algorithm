#include <iostream>
#include <queue>
#define MAX 200
using namespace std;

typedef pair<int, int> pii;

int dx[] = {-2,-2,0,0,2,2};
int dy[] = {-1,1,-2,2,-1,1};

int n, sx, sy, ex, ey;
int visit[MAX][MAX];

int bfs() {
	queue<pii> q;
	visit[sx][sy] = 1;
	q.emplace(sx, sy);
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (x == ex && y == ey) return visit[x][y] - 1;
		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n || visit[nx][ny]) continue;
			q.emplace(nx, ny);
			visit[nx][ny] = visit[x][y] + 1;
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> sx >> sy >> ex >> ey;
	cout << bfs();
}

/*
bfs로 목표 지점에 도착하는 최단 시간을 구해주었습니다.
*/