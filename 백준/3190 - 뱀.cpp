#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, k, a, b, l, x, t = 0, d = 0, sx = 0, sy = 0;
queue<pair<int, int>> q;
char c;
int board[100][100] = { 2, };
int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	while (k--) {
		cin >> a >> b;
		board[--a][--b] = 1;
	}
	cin >> l;
	q.push({ 0, 0 });
	for (int i = 0; i <= l; i++) {
		if (i != l) cin >> x >> c;
		else x = 10000;
		while (t < x) {
			t++;
			sx = sx + dx[d];
			sy = sy + dy[d];
			q.push({ sx, sy });
			if (sx < 0 || sy < 0 || sx >= n || sy >= n || board[sx][sy] == 2) {
				printf("%d", t);
				return 0;
			}
			else if (board[sx][sy] == 1) board[sx][sy] = 2;
			else if (board[sx][sy] == 0) {
				board[sx][sy] = 2;
				board[q.front().first][q.front().second] = 0;
				q.pop();
			}
		}
		d = c == 'D' ? (d + 3) % 4 : (d + 1) % 4;
	}
}