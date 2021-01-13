#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, sx, sy;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
vector<vector<char>> graph(50, vector<char>(50));
bool visited[50][50][64] = { false, };

int registerKey(int k, char c) {
	return k | (1 << (c-'a'));
}

bool open(int k, char c) {
	return k & (1 << (c - 'A')) ? true : false;
}

int bfs() {

	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {sx, sy}, {0, 0} });

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int t = q.front().second.first;
		int k = q.front().second.second;
		q.pop();
		if (graph[x][y] == '1') return t;
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m || visited[nx][ny][k] || graph[nx][ny] == '#') continue;
			if ('A' <= graph[nx][ny] && graph[nx][ny] <= 'Z' && !open(k, graph[nx][ny])) continue;

			if ('a' <= graph[nx][ny] && graph[nx][ny] <= 'z') {
				int kk = registerKey(k, graph[nx][ny]);
				visited[nx][ny][kk] = true;
				q.push({ {nx, ny}, {t + 1, kk} });
			}
			else {
				visited[nx][ny][k] = true;
				q.push({ {nx, ny}, {t + 1, k} });
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == '0') {
				sx = i;
				sy = j;
				graph[i][j] = '.';
			}
		}
	cout << bfs();
}
