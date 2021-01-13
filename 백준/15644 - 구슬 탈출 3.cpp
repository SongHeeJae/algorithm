#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, ans = 9999;

vector<int> p;
char path[11];

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
	if (f && ans > c) {
		ans = c;
		for (int i = 0; i < p.size(); i++) {
			if (p[i] == 0) path[i] = 'L';
			else if (p[i] == 1) path[i] = 'R';
			else if (p[i] == 2) path[i] = 'U';
			else path[i] = 'D';
		}
		return false;
	}
	return true;
}

void check(char map[][10], int c, int pDir) {
	if (c == 10 || c >= ans) return;
	char temp[10][10];
	copy(temp, map);
	for (int i = 0; i < 4; i++) {
		p.push_back(i);
		if (i != pDir && move(i, map, c)) check(map, c + 1, i);
		p.pop_back();
		copy(map, temp);
	}
}

int main() {
	char map[10][10];
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m && scanf(" %c", &map[i][j]); j++);
	check(map, 0, -1);
	if (ans == 9999) printf("-1");
	else {
		path[ans + 1] = '\0';
		printf("%d\n%s", ans + 1, path);
	}
}

/*
구슬 탈출 2 에서 지나왔던 경로만 추가적으로 기억해주면 되는 문제였습니다.

최솟값이 업데이트될 때마다 경로도 업데이트해주었습니다.

*/