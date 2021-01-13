#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

int n, m, h, a, b, ans = INF;
int map[31][11] = { 0, };

bool down() {
	for (int i = 1; i <= n; i++) {
		int p = i;
		for (int j = 1; j <= h; j++) {
			if (map[j][p] != 0) p = map[j][p];
		}
		if (i != p) return false;
	}
	return true;
}


void line(int idx, int c, int cnt) {
	if (c == cnt) {
		if (down()) {
			cout << cnt;
			exit(0);
		}
		return;
	}
	for (int i = idx; i <= h; i++) {
		for (int j = 1; j < n; j++) {
			if (map[i][j] == 0 && map[i][j+1] == 0) {
				map[i][j] = j + 1;
				map[i][j + 1] = j;
				line(i, c, cnt + 1);
				map[i][j] = 0;
				map[i][j + 1] = 0;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		map[a][b] = b + 1;
		map[a][b + 1] = b;
	}

	for (int i = 0; i < 4; i++) line(1, i, 0);

	cout << -1;
}
