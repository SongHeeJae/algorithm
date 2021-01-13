#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int n, m, x, y, t, ans = INF;
vector<vector<int>> map(50, vector<int>(50));
vector<pair<int, int>> virusBlock;
vector<pair<int, int>> virus;
vector<bool> virusVisited(10, false);

bool isPossible(vector<vector<bool>>& visited) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (map[i][j] != 1 && !visited[i][j]) return false;
	return true;
}

void bfs() {
	vector<vector<bool>> visited(n, vector<bool>(n, false));
	queue<pair<pair<int, int>, int>> q;
	for (int i = 0; i < virus.size(); i++) {
		q.push({ {virus[i].first, virus[i].second}, 0 });
		visited[virus[i].first][virus[i].second] = true;
	}
	while (!q.empty()) {
		x = q.front().first.first;
		y = q.front().first.second;
		t = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx >= 0 && yy >= 0 && xx < n && yy < n && !visited[xx][yy] && map[xx][yy] != 1) {
				visited[xx][yy] = true;
				q.push({ { xx, yy}, t + 1 });
			}
		}
	}
	t = isPossible(visited) ? t : INF;
	ans = min(t, ans);
}


void allVirus(int idx, int c) {
	if (c == m) {
		bfs();
		return;
	}
	for (int i = idx; i < virusBlock.size(); i++) {
		int xx = virusBlock[i].first;
		int yy = virusBlock[i].second;
		virus.push_back({ xx, yy });
		if (!virusVisited[i]) {
			virusVisited[i] = true;
			allVirus(i + 1, c + 1);
			virusVisited[i] = false;
			virus.pop_back();
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2) virusBlock.push_back({ i, j });
		}
	allVirus(0, 0);
	printf("%d\n", ans != INF ? ans : -1);
}