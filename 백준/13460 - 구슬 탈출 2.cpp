#include <iostream>
#include <algorithm>
int n, m, ans = 9999;

void copy(char a[][10], char b[][10]) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) a[i][j] = b[i][j];
}

bool move(int dir, char map[][10], int c) {
	int k, f = 0;
	if (dir == 0) { // 왼
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 'R') {
					map[i][j] = '.';
					for (k = j - 1; k >= 0 && map[i][k] == '.'; k--);
					if (map[i][k] == 'O') f = 1;
					else map[i][k + 1] = 'R';
				}
				else if (map[i][j] == 'B') {
					map[i][j] = '.';
					for (k = j - 1; k >= 0 && map[i][k] == '.'; k--);
					if (map[i][k] == 'O') return false;
					else map[i][k + 1] = 'B';
				}
			}
		}
	}
	else if (dir == 1) { // 오
		for (int i = 0; i < n; i++) {
			for (int j = m - 1; j >= 0; j--) {
				if (map[i][j] == 'R') {
					map[i][j] = '.';
					for (k = j + 1; k < m && map[i][k] == '.'; k++);
					if (map[i][k] == 'O') f = 1;
					else map[i][k - 1] = 'R';
				}
				else if (map[i][j] == 'B') {
					map[i][j] = '.';
					for (k = j + 1; k < m && map[i][k] == '.'; k++);
					if (map[i][k] == 'O') return false;
					else map[i][k - 1] = 'B';
				}
			}
		}
	}
	else if (dir == 2) { // 위
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 'R') {
					map[i][j] = '.';
					for (k = i - 1; k >= 0 && map[k][j] == '.'; k--);
					if (map[k][j] == 'O') f = 1;
					else map[k + 1][j] = 'R';
				}
				else if (map[i][j] == 'B') {
					map[i][j] = '.';
					for (k = i - 1; k >= 0 && map[k][j] == '.'; k--);
					if (map[k][j] == 'O') return false;
					else map[k + 1][j] = 'B';
				}
			}
		}
	}
	else { // 아래
		for (int i = n - 1; i >= 0; i--) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 'R') {
					map[i][j] = '.';
					for (k = i + 1; k < n && map[k][j] == '.'; k++);
					if (map[k][j] == 'O') f = 1;
					else map[k - 1][j] = 'R';
				}
				else if (map[i][j] == 'B') {
					map[i][j] = '.';
					for (k = i + 1; k < n && map[k][j] == '.'; k++);
					if (map[k][j] == 'O') return false;
					else map[k - 1][j] = 'B';
				}
			}
		}
	}
	if (f) {
		ans = std::min(ans, c);
		return false;
	}
	return true;
}

void check(char map[][10], int c, int pDir) {
	if (c == 10 || c >= ans) return;
	char temp[10][10];
	copy(temp, map);
	for (int i = 0; i < 4; i++) {
		if (i != pDir && move(i, map, c)) check(map, c + 1, i);
		copy(map, temp);
	}
}

int main() {
	char map[10][10];
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m && scanf(" %c", &map[i][j]); j++);
	check(map, 0, -1);
	printf("%d", ans != 9999 ? ans + 1 : -1);
}

/*
구슬 탈출 1과 유사한 문제였습니다. 이번에는 몇 번만에 탈출하는지 그 깊이의 최소를 구해주면 되었습니다.
*/