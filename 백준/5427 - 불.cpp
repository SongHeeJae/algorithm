#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
char graph[1000][1000];
bool visited[1000][1000];

vector<pair<int, int>> temp;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int t, n, m, sx, sy;

void fire(queue<pair<int, int>>& f) {
	int size = f.size();
	while (size--) {
		for (int i = 0; i < 4; i++) {
			int nx = f.front().first + dx[i];
			int ny = f.front().second + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (graph[nx][ny] != '.') continue;
			graph[nx][ny] = '*';
			f.push({ nx, ny });
		}
		f.pop();
	}
}


int bfs(queue<pair<int, int>>& f) {
	queue<pair<pair<int, int>, int>> q;

	int pt = 0, x, y, t;
	q.push({ {sx, sy}, 1 });
	visited[sx][sy] = true;
	while (!q.empty()) {
		x = q.front().first.first;
		y = q.front().first.second;
		t = q.front().second;
		q.pop();

		if (x == 0 || y == 0 || x == n - 1 || y == m - 1) return t;
		
		if (t != pt && f.size() != 0) {
			pt = t;
			fire(f);
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (visited[nx][ny]) continue;
			if (graph[nx][ny] != '.') continue;
			visited[nx][ny] = true;
			q.push({ {nx, ny}, t + 1 });
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--) {
		memset(visited, false, sizeof(visited));
		queue<pair<int, int>> f;
		cin >> m >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> graph[i][j];
				if (graph[i][j] == '@') {
					sx = i;
					sy = j;
					graph[i][j] = '.';
				}
				else if (graph[i][j] == '*') f.push({ i, j });
			}
		}
		int res = bfs(f);
		if (res != -1) cout << res << "\n";
		else cout << "IMPOSSIBLE\n";
	}
}
