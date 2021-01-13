#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
char graph[12][6];
bool visited[12][6];
vector<pair<int, int>> pos;

int cnt = 0;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void dfs(int x, int y, char c) {
	visited[x][y] = true;
	pos.push_back({ x, y });
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= 12 || ny >= 6) continue;
		if (!visited[nx][ny] && graph[nx][ny] == c) {
			dfs(nx, ny, c);
		}
	}
}

int main() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) graph[i][j] = getchar();
		getchar();
	}

	while (1) {
		bool f = true;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (!visited[i][j] && graph[i][j] != '.') {
					pos.clear();
					dfs(i, j, graph[i][j]);
					if (pos.size() > 3) {
						f = false;
						for (int k = 0; k < pos.size(); k++)
							graph[pos[k].first][pos[k].second] = '.';
					}
				}
			}
		}
		if (f) break;
		cnt++;
		for (int i = 0; i < 6; i++) {
			int k = 11;
			for (int j = 11; j >= 0; j--) {
				if (graph[j][i] != '.') {
					char temp = graph[j][i];
					graph[j][i] = '.';
					graph[k--][i] = temp;
				}
			}
		}
	}
	printf("%d", cnt);
}