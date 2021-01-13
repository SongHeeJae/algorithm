#include <iostream>
#include <vector>
using namespace std;

//북 동 남 서
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int main()
{
	int n, m, r, c, d, cnt = 1, temp;

	scanf("%d %d", &n, &m);
	scanf("%d %d %d", &r, &c, &d);
	vector<vector<int>> graph(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &graph[i][j]);

	graph[r][c] = -1;
	while (1) {
		bool f = false;
		for (int i = 0; i < 4; i++) { // 네방향 탐색
			temp = (d + (3 - i)) % 4;
			int dr = r + dx[temp];
			int dc = c + dy[temp];
			if (dr >= 0 && dc >= 0 && dr < n && dc < m && graph[dr][dc] == 0) {
				f = true;
				cnt++;
				d = temp;
				r = dr;
				c = dc;
				graph[r][c] = -1;
				break;
			}
		}

		if (!f) { // 후진 위치
			int backD = (d + 2) % 4;
			r = r + dx[backD];
			c = c + dy[backD];
			if (!(r >= 0 && c >= 0 && r < n && c < m && graph[r][c] != 1)) break;
		}
	}
	printf("%d\n", cnt);
}