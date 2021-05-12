#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int n, m, k, r, c, v = 0, ans = 0;
int map[40][40] = { 0 };
int s[10][10];
int visit[10][10] = { 0 };
vector<pair<int, int>> putPos; // 노트북에 스티커 붙일 좌표 기억

void rotate() { // 90도 회전
	int temp[10][10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			temp[i][j] = s[10 - j - 1][i];
		}
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			s[i][j] = temp[i][j];
		}
	}
}

bool dfs(int x, int y, int bx, int by) {
    // 이미 스티커가 붙여져있거나 노트북의 범위를 벗어나면 스티커를 붙일 수 없음 
	if (map[bx][by] == 1 || bx < 0 || by < 0 || bx >= n || by >= m)
		return false;
	visit[x][y] = v;
	putPos.push_back({ bx, by }); // 노트북에 붙일 좌표 기억
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= 10 || ny >= 10 || visit[nx][ny] == v || s[nx][ny] == 0) continue;
		if(!dfs(nx, ny, bx + dx[i], by + dy[i])) return false; // bx, by도 방향 따라감
	}
	return true;
}

void updateSticker() {
	for (int i = 0; i < putPos.size(); i++) {
		map[putPos[i].first][putPos[i].second] = 1;
	}
}

bool putSticker(int bx, int by) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (s[i][j] == 1) { // 스티커의 모든 좌표 DFS 돌며 붙일 수 있는지 확인
				putPos.clear(), v++;
				if (dfs(i, j, bx, by)) { // 붙일 수 있으면 수집한 좌표로 노트북에 스티커 업데이트
					updateSticker();
					return true;
				}
                return false;
			}
		}
	}
	return false;
}

bool findEmptySpace() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) { // 빈 공간 찾아서 스티커 붙이는 시도
                // 노트북에 붙일 실제 좌표 i, j 기억
				if (putSticker(i, j)) return true;
			}
		}
	}
	return false;
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < k; i++) {
		int cnt = 0, rcnt = 0, res;
		memset(s, 0, sizeof(s));
		scanf("%d %d", &r, &c);
		for (int j = 0; j < r; j++) {
			for (int k = 0; k < c; k++) {
				scanf("%d", &s[j][k]);
				if (s[j][k]) cnt++; // 스티커 칸 수 저장
			}
		}
		while (!(res = findEmptySpace())) { // 스티커 붙였으면 break
			if (++rcnt == 4) break;
			rotate(); // 회전
		}
		if (res) ans += cnt;
	}
	printf("%d", ans);
}

/*
빈 공간이 나오면 스티커를 붙이기 위한 시도를 해봅니다.
스티커를 붙일 수 있는 위치가 없다면, 스티커를 90도 회전한 뒤, 다시 처음부터 빈 공간에 스티커를 붙이기 위한 시도를 해봅니다.
위 과정을 스티커를 270도 회전한 결과까지 반복합니다.

노트북에 스티커를 붙이기 위한 방법은 다음과 같습니다.
스티커를 붙이기 위한 빈 공간 기준점의 좌표를 기억해줍니다.
스티커의 칸들을 DFS로 돌면서, 그 방향성을 가지고 기준점의 좌표를 업데이트해주며 기억해줍니다.
업데이트되는 기준점의 좌표들로 노트북에 스티커를 붙일 수 있다면, 노트북에 스티커를 붙여줍니다.
*/