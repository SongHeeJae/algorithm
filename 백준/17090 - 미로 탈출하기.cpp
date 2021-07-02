#include <iostream>
using namespace std;

int n, m, ans = 0;
char map[502][502] = { 0 };
pair<int, int> dp[502][502];
bool visit[502][502] = { false };

pair<int, int> dfs(int x, int y) {
	if (visit[x][y]) {
		if (!(dp[x][y].first == 0 && dp[x][y].second == 0)) return dp[x][y];
		else return dp[x][y] = { x, y };
	}
	if (map[x][y] == 0) return { x, y };
	visit[x][y] = true;
	int nx = x, ny = y;
	if (map[x][y] == 'U') nx--;
	else if (map[x][y] == 'R') ny++;
	else if (map[x][y] == 'D') nx++;
	else ny--;
	return dp[x][y] = dfs(nx, ny);
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", &map[i][1]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			pair<int, int> res = dfs(i, j);
			if (res.first < 1 || res.second < 1 || res.first > n || res.second > m) {
				ans++;
			}
		}
	}
	printf("%d", ans);
}

/*
dp[x][y] = (x, y) 좌표에서 출발했을 때 최종적으로 도착하는 지점의 좌표를 저장해주었습니다.
각 좌표마다 최종 지점까지 이동하면서 탈출 가능한 칸인지 검사해주었습니다.
*/