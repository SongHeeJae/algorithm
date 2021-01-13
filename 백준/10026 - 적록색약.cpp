#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int dx[] = { -1,1,0,0 };
int dy[] = { 0, 0,-1,1 };
char graph[100][100];

void dfs(bool visited[][100], int x, int y, char c) {
	visited[x][y] = true;
	if (graph[x][y] == 'R') graph[x][y] = 'G';
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		if (!visited[nx][ny] && graph[nx][ny] == c)
			dfs(visited, nx, ny, c);
	}
}

void f() {
	bool visited[100][100] = {false,};
	int c = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (!visited[i][j]) {
				dfs(visited, i, j, graph[i][j]);
				c++;
			}
	printf("%d\n", c);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		getchar();
		for (int j = 0; j < n; j++) graph[i][j] = getchar();
	}
	f();
	f();
}