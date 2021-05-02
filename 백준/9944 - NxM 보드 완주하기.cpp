#include <iostream>
#include <algorithm>
#include <cstring>
#define INF 2147483647
using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int n, m, ans, cnt, idx = 1;
char map[30][30];
bool visit[30][30];

void copy(bool a[][30], bool b[][30]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = b[i][j];
		}
	}
}

pair<int, pair<int, int>> move(int x, int y, int dir) {
	int c = 0;
	while (1) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m || visit[nx][ny]) break;
		visit[nx][ny] = true;
		x = nx, y = ny;
		c++;
	}
	return { c, { x, y } };
}

void dfs(int x, int y, int c, int d) {
	if (d >= ans) return;
	if (c == cnt) {
		ans = min(ans, d);
		return;
	}

	bool temp[30][30];
	copy(temp, visit);
	for (int i = 0; i < 4; i++) {
		pair<int, pair<int, int>> pos = move(x, y, i);
		if (pos.first != 0) {
			dfs(pos.second.first, pos.second.second, c + pos.first, d + 1);
			copy(visit, temp);
		}

	}
}

int main() {
	while (scanf("%d %d", &n, &m) == 2) {
		memset(visit, false, sizeof(visit));
		ans = INF;
		cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf(" %c", &map[i][j]);
				if (map[i][j] == '*') visit[i][j] = true;
				else cnt++;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == '.') {
					visit[i][j] = true;
					dfs(i, j, 1, 0);
					visit[i][j] = false;
				}
			}
		}
		printf("Case %d: %d\n", idx++, ans != INF ? ans : -1);
	}
}

/*
빈 칸인 모든 지점에 공을 놓았을 때, 모든 방향으로 가는 최소 이동 횟수를 구해주었습니다.
이미 구해진 최소 이동 횟수보다 더 높은 횟수의 이동은 더 이상 구할 필요가 없습니다.
또, 각 방향으로 이동할 때마다의 이전 상태를 기억해주었습니다.
*/