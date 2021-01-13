#include <iostream>
#include <queue>
#define INF 987654321
using namespace std;
int w, h, c[2], ans = 0;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
char map[100][100];
int visit[100][100] = { 0 };
queue<pair<pair<int, int>, pair<int, int>>> q;

int main() {
	scanf("%d %d", &w, &h);
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w && scanf(" %c", &map[i][j]); j++)
			if (map[i][j] == 'C')
				if (q.empty()) q.push({ { i, j }, {-1, -1} });
				else c[0] = i, c[1] = j;

	for (int i = 0; i < h; i++) // visit 초기화
		for(int j = 0; j < w; j++) visit[i][j] = INF;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int d = q.front().second.first;
		int n = q.front().second.second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= h || ny >= w || map[nx][ny] == '*') continue;
			int nn = i != d ? n + 1 : n;
			if (visit[nx][ny] >= nn) {
				visit[nx][ny] = nn;
				q.push({ {nx, ny}, {i, nn} });
			}
		}
	}
	printf("%d", visit[c[0]][c[1]]);
}

/*
pop할 때 방문 체크를 해주었습니다.

다음 이동할 거리에서 사용되어있는 거울의 갯수가 지금 위치에서 이동했을 때 사용될 거울의 갯수보다 같거나 많다면 push해주었습니다. 
*/