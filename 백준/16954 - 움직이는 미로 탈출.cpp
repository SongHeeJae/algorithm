#include <iostream>
#include <queue>
using namespace std;

int dx[] = { -1,1,0,0,-1,-1,1,1,0 };
int dy[] = { 0,0,-1,1,1,-1,1,-1,0 };

string map[8];
queue<vector<int>> q;
int visit[8][8] = { 0 };

void moveDown() {
	for (int i = 0; i < 8; i++) {
		for (int j = 7; j > 0; j--)
			map[j][i] = map[j-1][i];
		map[0][i] = '.';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 8; i++)
		cin >> map[i];

	int p = 1;
	q.push({ 7, 0, 1 });
	visit[7][0] = 1;
	while (!q.empty()) {
		int x = q.front()[0];
		int y = q.front()[1];
		int c = q.front()[2];
		if (x == 0 && y == 7) break;
		q.pop();
		if (c != p) {
			moveDown();
			p = c;
		}
		if (map[x][y] == '#') continue;
		for (int i = 0; i < 9; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= 8 || ny >= 8 || visit[nx][ny] == c + 1) continue;
			if (map[nx][ny] == '#') continue;
			q.push({ nx, ny, c + 1 });
			visit[nx][ny] = c + 1;
		}
	}
	printf("%d", q.empty() ? 0 : 1);
}

/*
1. 1초 내에 이동 가능한 위치들을 큐에 담아준다.
2. 초가 바뀌었으면, 벽을 움직인다.
3. 벽을 움직이고 난 뒤, 현재 있던 위치가 벽이라면 continue;
4. 1번으로 돌아간다.
위 과정을 반복하여 미로를 탈출할 수 있는지 여부를 구해주었습니다.
현재 위치에서 다음으로 이동 가능한 위치는, 상하좌우와 대각선과 제자리이므로 9방향입니다.
*/