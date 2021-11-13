#include <iostream>
#include <vector>
#include <queue>
#define MAX 102
using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int n, m;
bool map[MAX][MAX], visit[MAX][MAX];
vector<pair<int, int>> sw[MAX][MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		sw[x][y].push_back({ a, b });
	}

	int cnt = 1;
	queue<pair<int, int>> q;
	q.push({ 1, 1 });
	map[1][1] = visit[1][1] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (auto& p : sw[x][y]) {
			if (map[p.first][p.second]) continue;
			map[p.first][p.second] = true;
			for (int i = 0; i < 4; i++) {
				int nx = p.first + dx[i];
				int ny = p.second + dy[i];
				if (visit[nx][ny]) q.push({ nx, ny });
			}
			cnt++;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (visit[nx][ny] || !map[nx][ny]) continue;
			q.push({ nx, ny });
			visit[nx][ny] = true;
		}
	}
	cout << cnt;
}

/*
각 방을 지날 때마다 불을 켤 수 있는 방들을 모두 켜줍니다.
만약, 이번에 새롭게 불을 켜는 방의 상하좌우에 있는 방 중에서,
이미 방문했던 방이 있다면 그 방을 다시 큐에 넣어서 지금 불은 켠 방을 재탐색할 수 있도록 해줍니다.
*/