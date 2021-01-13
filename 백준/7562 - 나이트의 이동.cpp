#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

int bfs(int x1, int y1, int x2, int y2, int l) {
	vector<vector<bool>> visited(l, vector<bool>(l, false));
	queue<pair<pair<int, int>, int>> q;
	q.push({ { x1, y1 }, 0 });
	visited[x1][y1] = true;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int c = q.front().second;
		if (x == x2 && y == y2) return c;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < l && ny < l && !visited[nx][ny]) {
				visited[nx][ny] = true;
				q.push({{ nx, ny }, c + 1 });
			}
		}
	}
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int l, x1, y1, x2, y2;
		scanf("%d", &l);
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		printf("%d\n", bfs(x1, y1, x2, y2, l));
	}
}
