#include <cstdio>
int n, m, p[4][4], ans = -1;
bool v[4][4];
void f(int x, int y, int s) {
	if (x >= n) {
		if (ans < s) ans = s;
		return;
	}
	int nx = y == m - 1 ? x + 1 : x;
	int ny = (y + 1) % m;
	if (v[x][y]) f(nx, ny, s);
	else {
		v[x][y] = 1;
		f(nx, ny, s + p[x][y]);
		int i, val = p[x][y];
		for (i = x + 1; i < n && !v[i][y]; i++) { // 세로 확장
			val = val * 10 + p[i][y];
			v[i][y] = 1;
			f(nx, ny, s + val);  
		}
		while (i-- && i >= x + 1) v[i][y] = 0;
		for (val = p[x][y], i = y + 1 ; i < m && !v[x][i]; i++) { // 가로 확장
			val = val * 10 + p[x][i];
			v[x][i] = 1;
			f(nx, ny, s + val);
		}
		while (i-- && i >= y + 1) v[x][i] = 0;
		v[x][y] = 0;
	}
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) scanf("%1d", &p[i][j]);
	f(0, 0, 0);
	printf("%d", ans);
}

/*
종이를 가로, 세로로 확장시키면서 모든 경우에 대해서 합을 구해줬습니다.
*/
