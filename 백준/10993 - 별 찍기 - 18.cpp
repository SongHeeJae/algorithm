#include <cstdio>
#include <cstring>
char s[1023][2046];
int main() {
	int n, r = 1, c = 1, x = 0, y = 0;
	memset(s, ' ', sizeof(s));
	scanf("%d", &n);
	for (int i = 1; i < n; i++) r = r * 2 + 1, c = c * 2 + 3;
	x = n % 2 ? r - 1 : x;
	for (int i = n, rr = r, cc = c; i ; rr /= 2, cc = cc / 2 - 1, x += i % 2 ? -rr : rr, y += rr + 1, i--) {
		for (int j = 0; j < cc; j++) s[x][y + j] = '*';
		for (int j = 1; j < rr; j++)
			s[x + (i % 2 ? -j : j)][y + j] = s[x + (i % 2 ? -j : j)][y + cc - 1 - j] = '*';
	}
	for (int i = 0; i < r; i++) {
		s[i][n % 2 ? c / 2 + 1 + i : c - i] = '\0';
		printf("%s\n", s[i]);
	}
}