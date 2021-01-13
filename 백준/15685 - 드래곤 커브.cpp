#include <cstdio>
#include <cmath>
bool map[101][101] = { false };
int n, x, y, d, g, dx[] = {0,-1,0,1}, dy[] = {1,0,-1,0}, t[1024] = { 0 };
void curve(int &x, int &y, int d) {
	map[x][y] = true;
	x = x + dx[d];
	y = y + dy[d];
	map[x][y] = true;
}

void dragonCurve(int x, int y, int d, int g) {
	int cnt = pow(2, g);
	for (int i = 0; i < cnt; i++) curve(x, y, (t[i] + d) % 4);
}

int count() {
	int c = 0;
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			if (map[i][j] && map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1]) c++;
	return c;
}

void generate() {
	for (int i = 0; i < 10; i++) {
		int sz = pow(2, i), s = sz;
		for (int j = 0; j < sz; j++) t[s + j] = (t[s - j - 1] + 1) % 4;
	}
}
int main() {
	scanf("%d", &n);
	generate();
	while (n-- && scanf("%d %d %d %d", &y, &x, &d, &g)) dragonCurve(x, y, d, g);
	printf("%d", count());
}

/*

시작방향 0기준으로 시작했을 때,

0 세대 - 0
1 세대 - 0, 1
2 세대 - 0, 1, 2, 1
3 세대 - 0, 1, 2, 1, 2, 3, 2, 1
4 세대 - 0, 1, 2, 1, 2, 3, 2, 1, 2, 3, 0, 3, 2, 1

같은 형태가 됩니다. 이전 세대의 + 1을 역순으로 취했을 때의 값이 다음 세대의 새로운 값이 됩니다.

0, 1, 2, 3 으로 4개의 방향을 가지고 시작 방향은 d라면,
0 세대 - (0 + d) % 4, 
1 세대 - (0 + d) % 4, (1 + d) % 4
2 세대 - (0 + d) % 4, (1 + d) % 4, (2 + d) % 4, (1 + d) % 4
...

이런 형태를 가지게 됩니다.

0 <= d <= 10이므로, 10세대일 때 방향은 2^10 = 1024개까지 나오므로, 모든 세대가 가지는 값들을 미리 구해두었습니다.
그리고 각 세대는 2^d 만큼 커브를 해주었습니다.
*/