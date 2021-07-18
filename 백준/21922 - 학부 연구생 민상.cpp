#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[] = { -1,1,0,0 }; // 상 하 좌 우
int dy[] = { 0,0,-1,1 };
int nextDir[2][4] = { // 3, 4번 물건일 때 다음 방향
	{3,2,1,0},
	{2,3,0,1}
};

queue<vector<int>> q; // {x, y, d = 상0 하1 좌2 우3}
int n, m, map[2000][2000];
bool visit[2000][2000][4] = { false };

int getNextDirection(int obj, int dir) {
	return obj > 2 ? nextDir[obj - 3][dir] : dir;
}

void pushAirCond(int x, int y) {
	for (int i = 0; i < 4; i++) {
		q.push({ x, y, i });
		visit[x][y][i] = true;
	}
	map[x][y] = 0;
}

void blowWind() {
	while (!q.empty()) {
		int x = q.front()[0];
		int y = q.front()[1];
		int d = q.front()[2];
		int obj = map[x][y];
		q.pop();
		if (obj == 1 && d > 1 || obj == 2 && d < 2) continue;
		int nd = getNextDirection(obj, d);
		int nx = x + dx[nd];
		int ny = y + dy[nd];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m || visit[nx][ny][nd]) continue;
		q.push({ nx, ny, nd });
		visit[nx][ny][nd] = true;
	}
}

int getVisitSpaceCount() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cnt += visit[i][j][0] || visit[i][j][1] || visit[i][j][2] || visit[i][j][3];
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) pushAirCond(i, j);
		}
	}
	blowWind();
	cout << getVisitSpaceCount();
}

/*
에어컨이 있는 자리에서 네 방향의 바람을 큐에 기억하여 BFS를 수행해주었습니다.
*/