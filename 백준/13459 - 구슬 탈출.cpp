#include <iostream>
int n, m;

void copy(char a[][10], char b[][10]) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) a[i][j] = b[i][j];
}

bool move(int dir, char map[][10]) {
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
		printf("1");
		exit(0);
	}
	return true;
}

void check(char map[][10], int c, int pDir) {
	if (c == 10) return;
	char temp[10][10];
	copy(temp, map);
	for (int i = 0; i < 4; i++) {
		if (i != pDir && move(i, map)) check(map, c + 1, i);
		copy(map, temp);
	}
}

int main() {
	char map[10][10];
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m && scanf(" %c", &map[i][j]); j++);
	check(map, 0, -1);
	printf("0");
}

/*
상하좌우로 기울였을 때를 시뮬레이션하였습니다.
처음에 속도가 너무 느리게 나오곤했는데, 한번 기울였던 방향으로 연속해서 기울여줄 필요는 없어서 함수의 매개변수로 이전에 이동한 방향을 가리키는 pDir을 추가해주었습니다.
*/