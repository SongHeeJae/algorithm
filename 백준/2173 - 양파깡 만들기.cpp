#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, map[31][31], v[5];
int sw[31][31] = { 0 }, sh[31][31] = { 0 };
bool visit[31][31] = { false };
vector<vector<int>> arr, res;

void init() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			sh[j][i] = sh[j - 1][i] + map[j][i];
			sw[i][j] = sw[i][j - 1] + map[i][j];
		}
	}
}

int getTaste(int x, int y, int height, int width) {
	return sh[x + height - 1][y] - sh[x - 1][y]
		+ sh[x + height - 1][y + width - 1] - sh[x - 1][y + width - 1]
		+ sw[x][y + width - 2] - sw[x][y]
		+ sw[x + height - 1][y + width - 2] - sw[x + height - 1][y];
}

bool chk(int x, int y, int height, int width) {
	for (int i = x; i < x + height; i++)
		if (visit[i][y] || visit[i][y + width - 1]) return false;
	for (int i = y + 1; i < y + width - 1; i++)
		if (visit[x][i] || visit[x + height - 1][i]) return false;
	return true;
}

void visitCheck(int x, int y, int height, int width) {
	for (int i = x; i < x + height; i++)
		visit[i][y] = visit[i][y + width - 1] = true;
	for (int i = y + 1; i < y + width - 1; i++)
		visit[x][i] = visit[x + height - 1][i] = true;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++) scanf("%d", &map[i][j]);
	init();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 3; k + i <= n + 1; k++)
				for (int l = 3; l + j <= n + 1; l++)
					arr.push_back({ -getTaste(i, j, k, l), i, j, k, l });
	sort(arr.begin(), arr.end());
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < 5; j++) v[j] = arr[i][j];
		if (chk(v[1], v[2], v[3], v[4])) {
			visitCheck(v[1], v[2], v[3], v[4]);
			res.push_back({ -v[0], v[1], v[2], v[1] + v[3] - 1, v[2] + v[4] - 1 });
			if (--m == 0) break;
		}
	}
	if (m == 0) {
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < 5; j++) printf("%d ", res[i][j]);
			printf("\n");
		}
	}
	else {
		printf("0");
	}
}

/*
먼저 과자판에서 각 좌표의 가로와 세로에 대한 누적합을 구해둡니다.
그리고 모든 좌표를 돌면서, 각 좌표에서 만들 수 있는 모든 양파깡의 맛 크기를 기억해줍니다.
맛 크기를 내림차순으로 정렬한 뒤, 순서대로 만들 수 있는 M개의 양파깡들을 구해줍니다.
*/