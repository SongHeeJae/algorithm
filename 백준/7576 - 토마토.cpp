#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dx[] = { -1,0, 0, 1 };
int dy[] = { 0, 1, -1, 0 };

int main() {
	int n, m, day = 0, c1 = 0, c2 = 0, c3 = 0;
	scanf("%d %d", &m, &n);
	vector<vector<int>> box(n, vector<int>(m));
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &box[i][j]);
			if (box[i][j] == 1)
				q.push(make_pair(i, j));
			else if (box[i][j] == 0) c1++;
			else if (box[i][j] == -1) c3++;
		}
	}

	if (q.empty()) {
		printf("-1\n");
		return 0;
	}

	if (q.size() == m * n - c3) {
		printf("0\n");
		return 0;
	}

	while (!q.empty()) {
		pair<int, int> s = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = s.first + dx[i];
			int yy = s.second + dy[i];
			if (xx >= 0 && yy >= 0 && xx < n && yy < m &&
				box[xx][yy] == 0) {
				box[xx][yy] = box[s.first][s.second] + 1;
				q.push(make_pair(xx, yy));
				day = max(box[xx][yy], day);
				c2++;
			}
		}
	}

	printf("%d\n", c1 == c2 ? day - 1: -1);
}
