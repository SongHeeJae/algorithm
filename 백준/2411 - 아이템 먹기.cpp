#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, a, b, x, y, map[101][101] = { 0 }, dp[101][101] = { 0 };
vector<pair<int, int>> items;

bool comp(pair<int, int>& a, pair<int, int>& b) {
	if (a.first == b.first) return a.second < b.second;
	else return a.first < b.first;
}

int main() {
	scanf("%d %d %d %d", &n, &m, &a, &b);
	while (a--) {
		scanf("%d %d", &x, &y);
		items.push_back({ x, y });
	}
	while (b--) {
		scanf("%d %d", &x, &y);
		map[x][y] = 1;
	}
	items.push_back({ 1, 1 });
	sort(items.begin(), items.end(), comp);
	items.push_back({ n, m });
	dp[1][1] = 1;
	for (int i = 0; i <= n; i++) map[i][0] = 1;
	for (int i = 0; i <= m; i++) map[0][i] = 1;
	for (int i = 1; i < items.size(); i++) {
		int sx = items[i - 1].first;
		int sy = items[i - 1].second;
		int ex = items[i].first;
		int ey = items[i].second;
		if (sx == ex && sy == ey) continue;
		for (int j = sx; j <= ex; j++) {
			for (int k = sy; k <= ey; k++) {
				if (map[j][k] == 1) continue;
				if (map[j - 1][k] != 1 && map[j][k - 1] != 1) {
					dp[j][k] = dp[j - 1][k] + dp[j][k - 1];
				}
				else if (map[j - 1][k] != 1) {
					dp[j][k] = dp[j - 1][k];
				}
				else if(map[j][k - 1] != 1){
					dp[j][k] = dp[j][k - 1];
				}
			}
		}
	}
	printf("%d", dp[n][m]);
}

/*
먼저 아이템을 먹는 순서대로 정렬(x좌표 오름차순, y좌표 오름차순)해주고,  주어진 장애물의 좌표를 기억해줍니다.
각 아이템을 순서대로 먹으면서 이동 가능한 경로들의 수를 업데이트해줍니다.
dp[i][j] = (1,1)에서 (i, j)까지 이동 가능한 경로들의 수입니다. 
dp[i][j] = (i-1, j), (i, j-1)이 장애물이 아니라면, 두 경로의 수를 합쳐주면 됩니다.
    (i-1, j) 또는 (i, j-1)만 장애물이 아니라면, 그 경로의 수를 그대로 기억해주면 됩니다.
*/