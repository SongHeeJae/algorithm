#include <cstdio>
#include <algorithm>

int minNum(char map[][51], int n, int m, int x, int y, int res) {
	if (x + 7 >= n) return res;
	
	int num1 = 0, num2 = 0;
	for (int i = x; i < x + 8; i++) {
		for (int j = y; j < y + 8; j++) {
			if ((i + j) % 2 == (x + y) % 2 && 'B' == map[i][j]) num1++;
			else if ((i + j) % 2 != (x + y) % 2 && 'W' == map[i][j]) num1++;

			if ((i + j) % 2 == (x + y) % 2 && 'W' == map[i][j]) num2++;
			else if ((i + j) % 2 != (x + y) % 2 && 'B' == map[i][j]) num2++;
		}
	}
	num1 = std::min(num1, num2);
	
	y++;
	if (y == m - 7) {
		y = 0;
		x++;
	}
	return minNum(map, n, m, x, y, std::min(res, num1));
}

int main() {
	int n, m;
	char map[51][51];
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
			scanf("%s", map[i], sizeof(map[i]));

	printf("%d", minNum(map, n, m, 0, 0, 987654321));
}