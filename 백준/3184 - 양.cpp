#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#define MAX 250
using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int r, c, aoc = 0, avc = 0;
string map[MAX];

void bfs(int x, int y) {
	int oc = map[x][y] == 'o';
	int vc = map[x][y] == 'v';
	queue<pair<int, int>> q;
	q.push({ x, y });
	map[x][y] = '#';
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
			if (map[nx][ny] == '#') continue;
			q.push({ nx, ny });
			oc += map[nx][ny] == 'o';
			vc += map[nx][ny] == 'v';
			map[nx][ny] = '#';
		}
	}
	if (oc > vc) vc = 0;
	else oc = 0;
	aoc += oc;
	avc += vc;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> map[i];
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] != '#') {
				bfs(i, j);
			}
		}
	}
	cout << aoc << " " << avc;
}

/*
울타리 내에 속한 영역마다 양과 늑대의 수를 구해주었습니다.
*/