#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
#define MAX 101

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int t, h, w, o, f, sx, sy, ex, ey, x, y, l;
int map[MAX][MAX];
bool visit[MAX][MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		memset(map, 0, sizeof(map));
		memset(visit, false, sizeof(visit));
		cin >> h >> w >> o >> f >> sx >> sy >> ex >> ey;
		while (o--) {
			cin >> x >> y >> l;
			map[x][y] = l;
		}

		queue<pair<pair<int, int>, int>> q;
		q.push({ {sx, sy}, f });
		visit[sx][sy] = true;
		while (!q.empty()) {
			int cx = q.front().first.first;
			int cy = q.front().first.second;
			int cf = q.front().second;
			if (cx == ex && cy == ey) break;
			q.pop();
			if (cf <= 0) continue;
			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				int nf = cf - 1;
				if (nx < 1 || ny < 1 || nx > h || ny > w) continue;
				int diff = map[nx][ny] - map[cx][cy];
				if (cf < diff) continue;
				if (visit[nx][ny]) continue;
				visit[nx][ny] = true;
				q.push({ {nx, ny}, nf });
			}
		}
		if (!q.empty()) cout << "잘했어!!\n";
		else cout << "인성 문제있어??\n";
	}
}

/*
BFS를 수행하며 주어진 힘으로 도착 지점에 갈 수 있는지 구해주었습니다.
*/