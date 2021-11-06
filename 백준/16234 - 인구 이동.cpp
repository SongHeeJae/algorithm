#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define MAX 50

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int n, l, r;
int map[MAX][MAX];
int visit[MAX][MAX], v = 1;

int dfs(int x, int y, vector<pair<int, int>>& tmp) {
	int s = map[x][y];
	visit[x][y] = v;
	tmp.push_back({ x, y });
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n || visit[nx][ny] == v) continue;
		int diff = abs(map[x][y] - map[nx][ny]);
		if (diff < l || diff > r) continue;
		s += dfs(nx, ny, tmp);
	}
	return s;
}

int groupingAndReturnSum(int sx, int sy, vector<pair<int, int>>& grp) {
	grp.clear();
	return dfs(sx, sy, grp);
}

bool hasMovableCountry(vector<pair<int, int>>& grp) {
	return grp.size() > 1;
}

int calPopulation(int sum, int grpSize) {
	return sum / grpSize;
}

void updateGroupCountryPopulation(vector<pair<int, int>>& grp, int sum) {
	int population = calPopulation(sum, grp.size());
	for (auto& country : grp) {
		map[country.first][country.second] = population;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	vector<pair<int, int>> grp;
	while (1) {
		bool finished = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visit[i][j] == v) continue;
				int sum = groupingAndReturnSum(i, j, grp);
				if (hasMovableCountry(grp)) {
					finished = false;
					updateGroupCountryPopulation(grp, sum);
				}
			}
		}
		if (finished) break;
		v++;
	}
	cout << v - 1;
}

/*
더 이상 인구 이동이 수행되지 않을 때까지 연합 국가들의 인구를 동일하게 조정해주었습니다.
*/