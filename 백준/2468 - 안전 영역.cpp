#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define MAX 100
using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int n, map[MAX][MAX], ans = 1;
int visit[MAX][MAX] = { 0 };
set<int> h;

void dfs(int x, int y, int rain) {
	visit[x][y] = rain;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		if (visit[nx][ny] == rain || map[nx][ny] <= rain) continue;
		dfs(nx, ny, rain);
	}
}

int countSafetyZone(int rain) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] > rain && visit[i][j] != rain) {
				dfs(i, j, rain);
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			h.insert(map[i][j]);
		}
	}

	for (int hh : h) {
		ans = max(ans, countSafetyZone(hh));
	}

	printf("%d", ans);
}

/*
각 높이만큼 비가 내렸을 때, 각 경우마다 안전 영역 개수를 구해주었습니다.
*/