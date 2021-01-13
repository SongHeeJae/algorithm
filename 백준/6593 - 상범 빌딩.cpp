#include <iostream>
#include <queue>
using namespace std;

int l, r, c, sx, sy, sz, ex, ey, ez, x, y, z, t, nx, ny, nz;
int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, -1, 1, 0, 0};
int dz[] = {0, 0, 0, 0, -1, 1};
char graph[30][30][30];

void bfs() {
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {sx,sy}, {sz,0} });
	graph[sz][sx][sy] = '#';
	while (!q.empty()) {
		x = q.front().first.first;
		y = q.front().first.second;
		z = q.front().second.first;
		t = q.front().second.second;
		q.pop();
		for (int i = 0; i < 6; i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			nz = z + dz[i];
			if (nx < 0 || ny < 0 || nz < 0 || nx >= r || ny >= c || nz >= l) continue;
			if (graph[nz][nx][ny] != '#') {
				if (nx == ex && ny == ey && nz == ez) {
					printf("Escaped in %d minute(s).\n", t + 1);
					return;
				}
				graph[nz][nx][ny] = '#';
				q.push({ {nx, ny}, {nz, t + 1} });
			}
		}
	}
	printf("Trapped!\n");
}

int main() {
	
	while (1) {
		scanf("%d %d %d", &l, &r, &c);
		if (l == 0) break;
		for (int i = 0; i < l; i++) {
			getchar();
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					graph[i][j][k] = getchar();
					if (graph[i][j][k] == 'S') {
						sx = j;
						sy = k;
						sz = i;
					}
					else if (graph[i][j][k] == 'E') {
						ex = j;
						ey = k;
						ez = i;
					}
				}
				getchar();
			}
		}
		bfs();
	}
}