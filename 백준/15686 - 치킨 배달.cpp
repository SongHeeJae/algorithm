#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

vector<pair<int, int>> house, chicken, chicken_pick;
int n, m, a, ans = INF;

void chicken_city() {
	int td = 0;
	for (int i = 0; i < house.size(); i++) {
		int d = INF;
		for (int j = 0; j < chicken_pick.size(); j++)
			d = min(d, abs(house[i].first - chicken_pick[j].first) + abs(house[i].second - chicken_pick[j].second));
		td += d;
	}
	ans = min(td, ans);
}

void dfs(vector<bool>& visited, int idx, int c, int m) {
	if (c == m) {
		chicken_city();
		return;
	}
	for (int i = idx; i < chicken.size(); i++)
		if (!visited[i]) {
			visited[i] = true;
			chicken_pick.push_back({ chicken[i].first, chicken[i].second });
			dfs(visited, i + 1, c + 1, m);
			visited[i] = false;
			chicken_pick.pop_back();
		}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &a);
			if (a == 1) house.push_back({i, j});
			else if (a == 2) chicken.push_back({i, j});
		}
	vector<bool> visited(chicken.size(), false);
	dfs(visited, 0, 0, m);
	printf("%d\n", ans);
}