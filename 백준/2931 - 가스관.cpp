#include <iostream>
int n, m, sx, sy, ex, ey, ax, ay;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
char graph[25][25];
bool visited[25][25] = { false, };
void dfs(int x, int y);
void checkDirection(int x, int y, int s, int e, int p) {
	for (int i = s; i < e; i += p) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny]) {
			if (graph[nx][ny] != '.')
				dfs(nx, ny);
			else
				if ((x != sx || y != sy) && (x != ex || y != ey)) {
					ax = nx;
					ay = ny;
				}
		}
	}
}
void dfs(int x, int y) {
	visited[x][y] = true;
	if (graph[x][y] == 'M' || graph[x][y] == 'Z') checkDirection(x, y, 0, 4, 1);
	else if (graph[x][y] == '|') checkDirection(x, y, 0, 2, 1);
	else if (graph[x][y] == '-') checkDirection(x, y, 2, 4, 1);
	else if (graph[x][y] == '+') checkDirection(x, y, 0, 4, 1);
	else if (graph[x][y] == '1') checkDirection(x, y, 1, 4, 2);
	else if (graph[x][y] == '2') checkDirection(x, y, 0, 4, 3);
	else if (graph[x][y] == '3') checkDirection(x, y, 0, 3, 2);
	else if (graph[x][y] == '4') checkDirection(x, y, 1, 3, 1);
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		getchar();
		for (int j = 0; j < m; j++) {
			graph[i][j] = getchar();
			if (graph[i][j] == 'M') {
				sx = i;
				sy = j;
			}
			else if (graph[i][j] == 'Z') {
				ex = i;
				ey = j;
			}
		}
	}
	dfs(sx, sy);
	dfs(ex, ey);
	bool f[4] = { false, };
	for (int i = 0; i < 4; i++) {
		int nx = ax + dx[i];
		int ny = ay + dy[i];
		if (nx >= 0 && ny >= 0 && nx < n && ny < m && graph[nx][ny] != '.')
			if (i == 0) {
				if (graph[nx][ny] == '|' || graph[nx][ny] == '+' || graph[nx][ny] == '1' || graph[nx][ny] == '4')
					f[i] = true;
			}
			else if (i == 1) {
				if (graph[nx][ny] == '|' || graph[nx][ny] == '+' || graph[nx][ny] == '2' || graph[nx][ny] == '3')
					f[i] = true;
			}
			else if (i == 2) {
				if (graph[nx][ny] == '-' || graph[nx][ny] == '+' || graph[nx][ny] == '1' || graph[nx][ny] == '2')
					f[i] = true;
			} 
			else {
				if (graph[nx][ny] == '-' || graph[nx][ny] == '+' || graph[nx][ny] == '3' || graph[nx][ny] == '4')
					f[i] = true;
			}
	}
	printf("%d %d ", ax + 1, ay + 1);
	if (f[0] && f[1] && f[2] && f[3]) printf("+");
	else if (f[0] && f[1]) printf("|");
	else if (f[2] && f[3]) printf("-");
	else if (f[1] && f[3]) printf("1");
	else if (f[0] && f[3]) printf("2");
	else if (f[0] && f[2]) printf("3");
	else if (f[1] && f[2]) printf("4");
}