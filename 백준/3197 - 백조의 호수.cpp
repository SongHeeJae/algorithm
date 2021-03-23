#include <iostream>
#include <queue>
using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int r, c, sx = -1, sy, ex, ey, cnt = 0;
char map[1500][1501];
bool visit1[1500][1500] = { false }; // sq visit
bool visit2[1500][1500] = { false }; // gq visit

queue<pair<int, int>> gq1, gq2, sq1, sq2; // gq 빙하, sq 백조

void init() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] == 'X') { // 첫 날 녹을 수 있는 빙하 푸시
				for (int k = 0; k < 4; k++) {
					int x = i + dx[k];
					int y = j + dy[k];
					if (x < 0 || y < 0 || x >= r || y >= c || map[x][y] == 'X') continue;
					gq1.push({ i, j });
					visit2[i][j] = true;
					break;
				}
			}
			else if (map[i][j] == 'L') {
				if (sx == -1) sx = i, sy = j;
				else ex = i, ey = j;
			}
		}
	}
	sq1.push({sx, sy}); // 백조 시작 위치 푸시
	visit1[sx][sy] = true;
}

int main() {
	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; i++) scanf("%s", map[i]);
	init();
	while (1) {
		queue<pair<int, int>>& currgq = cnt % 2 ? gq2 : gq1;
		queue<pair<int, int>>& nextgq = cnt % 2 ? gq1 : gq2;
		queue<pair<int, int>>& currsq = cnt % 2 ? sq2 : sq1;
		queue<pair<int, int>>& nextsq = cnt % 2 ? sq1 : sq2;
    
        // 백조 이동 위치 먼저 BFS
		while (!currsq.empty()) {
			int x = currsq.front().first;
			int y = currsq.front().second;
			currsq.pop();
			if (x == ex && y == ey) {
				printf("%d", cnt);
				return 0;
			}
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (x < 0 || y < 0 || x >= r || y >= c) continue;
				if (visit1[nx][ny]) continue;
				visit1[nx][ny] = true;
                // 바로 옆 위치가 빙하여서 못간다면, 다음 번엔 갈 수 있으니 그 곳에서부터 다시 BFS
				if (map[nx][ny] != 'X') currsq.push({ nx, ny });
				else nextsq.push({ nx, ny });
			}
		}

        // 빙하 녹이기
		while (!currgq.empty()) {
			int x = currgq.front().first;
			int y = currgq.front().second;
			currgq.pop();
			map[x][y] = '.';
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (x < 0 || y < 0 || x >= r || y >= c || visit2[nx][ny] || map[nx][ny] != 'X') continue;
				// 지금 녹이는 지점의 사방이 빙하라면, 다음 번에 녹일 수 있는 빙하
                visit2[nx][ny] = true;
				nextgq.push({ nx, ny });
			}
		}
		cnt++;
	}
}

/*
네 개의 큐를 사용하였습니다.

- 지금 녹을 빙하
- 다음에 녹을 빙하
- 지금 백조가 이동 가능한 지점들의 BFS 시작점
- 다음 백조가 이동 가능한 지점들의 BFS 시작점

1. 첫 날 녹을 빙하를 큐에 기억해주고, 백조의 시작점을 기억해줍니다.
2. 먼저 백조가 이동 가능한 지점들을 모두 탐색해줍니다.
3. 다른 백조에게 접근할 수 있으면 종료합니다.
4. 지금 백조가 이동 불가능한 지점이 빙하라면, 다음 번에는 빙하가 녹기 때문에 이동 가능합니다.
5. 빙하를 녹여줍니다.
6. 빙하를 녹일 때, 사방을 검사하면서 해당 좌표가 빙하라면, 다음 번에 녹을 수 있습니다.
7. 위 2~6 과정을 반복합니다.
*/