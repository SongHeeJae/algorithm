#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int n, m, ans = 0, v = 1;
int map[1002][1002] = { 0 };
int idx[1000 * 1000 / 2];
int visit[1002][1002] = { 0 };
set<int> st;

int dfs(int x, int y) {
	visit[x][y] = v;
	int c = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (visit[nx][ny] == v || map[nx][ny] == 0) continue;
		c += dfs(nx, ny);
	}
	return c;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> map[i][j];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (map[i][j] == 1 && visit[i][j] == 0)
				idx[v++] = dfs(i, j);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 0) {
				st.clear();
				for (int k = 0; k < 4; k++) {
					st.insert(visit[i + dx[k]][j + dy[k]]);
					int sum = 1;
					for (auto it = st.begin(); it != st.end(); it++)
						sum += idx[*it];
					ans = max(ans, sum);
				}
			}
		}
	}
	cout << ans;
}

/*
각 모양마다 번호를 붙여서 그 개수를 전처리해주었습니다.
그 후, 기존 배열에서 0이 나올 때마다 상하좌우를 검사하여 인접한 모양들의 번호를 구하고,
그 번호에 이미 전처리되어있는 모양의 개수를  더해주었습니다.
*/