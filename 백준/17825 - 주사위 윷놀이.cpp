#include <iostream>
#include <algorithm>
using namespace std;

int arr[10], ans = 0, pos[5] = { 0 }, map[33], jump[33][6];
bool visit[33] = { false };

void initMap() {
	for (int i = 0; i < 21; i++) map[i] = i * 2;
	for (int i = 21; i < 24; i++) map[i] = 3 * i - 50;
	for (int i = 24; i < 26; i++) map[i] = 2 * i - 26;
	for (int i = 26; i < 29; i++) map[i] = 54 - i;
	for (int i = 29; i < 32; i++) map[i] = 5 * i - 120;
	map[32] = 0;
}

void initJump() {
	for (int i = 0; i <= 20; i++) {
		for (int j = 1; j <= 5; j++) {
			if (i + j > 20) jump[i][j] = 32;
			else jump[i][j] = i + j;
		}
	}
	jump[5][1] = 21;
	jump[5][2] = 22;
	jump[5][3] = 23;
	jump[5][4] = jump[10][3] = jump[15][4] = 29;
	jump[5][5] = jump[10][4] = jump[15][5] = 30;
	jump[10][1] = 24;
	jump[10][2] = 25;
	jump[10][5] = 31;
	jump[15][1] = 26;
	jump[15][2] = 27;
	jump[15][3] = 28;
	for (int i = 21; i < 24; i++) {
		for (int j = 1; j <= 5; j++) {
			if (j >= 24 - i) jump[i][j] = i + j + 5;
			else jump[i][j] = i + j;
		}
	}
	for (int i = 24; i < 26; i++) {
		for (int j = 1; j <= 5; j++) {
			if (j >= 26 - i) jump[i][j] = i + j + 3;
			else jump[i][j] = i + j;
		}
	}
	for (int i = 26; i < 29; i++) {
		for (int j = 1; j <= 5; j++) {
			jump[i][j] = i + j;
		}
	}
	for (int i = 29; i < 32; i++) {
		for (int j = 1; j <= 5; j++) {
			if (i + j > 32) jump[i][j] = 32;
			else jump[i][j] = i + j;
		}
	}
	jump[22][5] = jump[23][4] = jump[24][5] = jump[25][4] = jump[27][5] = jump[28][4] = jump[29][3] = jump[30][2] = jump[31][1] = 20;
	jump[23][5] = jump[25][5] = jump[28][5] = jump[29][4] = jump[29][5] = jump[30][3] = jump[31][2] = 32;
	for (int i = 1; i <= 5; i++)
		jump[32][i] = 32;
}

int nextPos(int node, int j) {
	return jump[pos[node]][j];
}

void dfs(int idx, int sum) {
	if (idx == 10) {
		ans = max(ans, sum);
		return;
	}
	for (int i = 0; i < 5; i++) {
		if (pos[i] == 32) continue;
		int nPos = nextPos(i, arr[idx]);
		if (nPos < 32 && visit[nPos]) continue;
		int pPos = pos[i];
		visit[pPos] = false;
		visit[nPos] = true;
		pos[i] = nPos;
		dfs(idx + 1, sum + map[nPos]);
		visit[pPos] = true;
		visit[nPos] = false;
		pos[i] = pPos;
	}
}

int main() {
	initMap();
	initJump();
	for (int i = 0; i < 10; i++)
		scanf("%d", &arr[i]);
	dfs(0, 0);
	printf("%d", ans);
}

/*
각 칸마다의 점수와 번호, 각 칸에서 이동했을 때의 도착하는 좌표를 전처리해둔 뒤 모든 경우를 검사하였습니다.
*/