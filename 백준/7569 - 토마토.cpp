#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

int dx[] = { -1,1, 0, 0, 0, 0 };
int dy[] = { 0, 0, -1, 1, 0, 0 };
int dz[] = { 0, 0, 0, 0, 1, -1 };

int main() {
	int n, m, h, day = 0, c1 = 0, c2 = 0, c3 = 0, hh, nn, mm;
	scanf("%d %d %d", &m, &n, &h);
	vector<vector<vector<int>>> box(h + 2, vector<vector<int>>(n + 2, vector<int>(m + 2, -1)));
	queue<tuple<int, int, int>> q;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= m; k++) {
				scanf("%d", &box[i][j][k]);
				if (box[i][j][k] == 1)
					q.push(make_tuple(i, j, k));
				else if (box[i][j][k] == 0) c1++;
				else if (box[i][j][k] == -1) c3++;
			}
		}
	}

	if (q.empty()) {
		printf("-1\n");
		return 0;
	}

	if (q.size() == m * n * h - c3) {
		printf("0\n");
		return 0;
	}

	while (!q.empty()) {
		tie(hh, nn, mm) = q.front();
		q.pop();
		for (int i = 0; i < 6; i++) {
			int hhh = hh + dx[i];
			int nnn = nn + dy[i];
			int mmm = mm + dz[i];
			if (box[hhh][nnn][mmm] == 0) {
				box[hhh][nnn][mmm] = box[hh][nn][mm] + 1;
				q.push(make_tuple(hhh, nnn, mmm));
				day = max(box[hhh][nnn][mmm], day);
				c2++;
			}
		}
	}

	printf("%d\n", c1 == c2 ? day - 1: -1);
}
