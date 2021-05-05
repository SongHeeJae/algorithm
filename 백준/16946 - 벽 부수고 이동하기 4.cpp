#include <iostream>
#include <set>
using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int n, m, v = 1;
int map[1000][1000];
int visit[1000][1000] = { 0 };
int idx[1000 * 1000 / 2] = { 0 };

set<int> st;

int dfs(int x, int y) {
	visit[x][y] = v;
	int c = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m || visit[nx][ny] == v || map[nx][ny]) continue;
		c += dfs(nx, ny);
	}
	return c;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%1d", &map[i][j]);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0 && visit[i][j] == 0) {
				idx[v] = dfs(i, j);
				v++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1) {
				st.clear();
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
					st.insert(visit[nx][ny]);
				}

				int s = 1;
				for (auto it = st.begin(); it != st.end(); it++)
					s += idx[*it];
				map[i][j] = s % 10;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			printf("%d", map[i][j]);
		printf("\n");
	}
}

/*
먼저 인접한 각 빈칸 그룹에 번호를 부여하고, 그 그룹에 속한 빈칸의 갯수를 기억해주었습니다.
예를 들어, 다음 그룹은
4 5
11001
00111
01010
10101
아래와 같이 전처리 해둡니다.
00110
22000
20304
05060
idx[1] = 2;
idx[2] = 3;
idx[3] = 1;
idx[4] = 1;
idx[5] = 1;
idx[6] = 1;
그 후, (x, y) == 0인 지점의 4방향을 검사해서, 그 지점을 포함시켰을 때의 같은 그룹에 속한 개수를 구해주었습니다.
*/