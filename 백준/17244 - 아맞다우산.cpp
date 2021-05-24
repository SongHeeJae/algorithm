#include <iostream>
#include <queue>
#include <algorithm>
#include <deque>
#define INF 2147483647
using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int n, m, sx, sy, ex, ey, v = 0, ans = INF;
deque<pair<int, int>> pos;
bool visit[7] = { false };
char map[50][51];
int mvisit[50][50] = { 0 };
int cache[7][7] = { 0 };

int getDist(int pos1, int pos2) {
	if (cache[pos1][pos2]) return cache[pos1][pos2];
	int x1 = pos[pos1].first, y1 = pos[pos1].second;
	int x2 = pos[pos2].first, y2 = pos[pos2].second;
	queue<vector<int>> q;
	q.push({ x1, y1, 0 });
	mvisit[x1][y1] = ++v;
	while (!q.empty()) {
		int x = q.front()[0];
		int y = q.front()[1];
		int c = q.front()[2];
		if (x == x2 && y == y2) {
			return cache[pos1][pos2] = cache[pos2][pos1] = c;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx < 0 || ny < 0 || nx >= m || ny >= n || mvisit[nx][ny] == v || map[nx][ny] == '#') continue;
			q.push({ nx, ny, c + 1 });
			mvisit[nx][ny] = v;
		}
	}
	return -1;
}

void dfs(int p, int dist, int depth) {
	if (depth == pos.size() - 2) {
		ans = min(ans, dist + getDist(p, pos.size() - 1));
		return;
	}
	for (int i = 1; i < pos.size() - 1; i++) {
		if (visit[i]) continue;
		visit[i] = true;
		dfs(i, dist + getDist(p, i), depth + 1);
		visit[i] = false;
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%s", &map[i]);
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 'S') sx = i, sy = j;
			else if (map[i][j] == 'E') ex = i, ey = j;
			else if (map[i][j] == 'X') pos.push_back({ i, j });
		}
	}
	pos.push_front({ sx, sy });
	pos.push_back({ ex, ey });
	dfs(0, 0, 0);
	printf("%d", ans);
}

/*
물건들의 위치를 나열하는 모든 순서쌍을 만든 뒤,
그 순서로 방문했을 때의 거리를 구하여 최소거리를 업데이트 해주었습니다.
*/