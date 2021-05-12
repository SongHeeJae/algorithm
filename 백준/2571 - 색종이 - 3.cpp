#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> pos;
int n, a, b, ans = 100;
int map[101][101] = { 0 };

int getHeight(int x, int y, int c) {
	int height = 0;
	while (map[x][y] == c) x++, height++;
	return height;
}

int getWidth(int x, int y, int c) {
	int width = 0;
	while (map[x][y] == c) y++, width++;
	return width;
}

pair<int, int> getMaxHeightPos(int x, int y, int width) {
	int up, down, i;
	for (up = x; map[up][y] != 0; up--) {
		for (i = 0; i < width && map[up][y + i] != 0; i++);
		if (i != width) break;
	}
	for (down = x; map[down][y] != 0; down++) {
		for (i = 0; i < width && map[down][y + i] != 0; i++);
		if (i != width) break;
	}
	return { up + 1, down - 1 };
}

pair<int, int> getMaxWidthPos(int x, int y, int height) {
	int left, right, i;
	for (left = y; map[x][left] != 0; left--) {
		for (i = 0; i < height && map[x + i][left] != 0; i++);
		if (i != height) break;
	}
	for (right = y; map[x][right] != 0; right++) {
		for (i = 0; i < height && map[x + i][right] != 0; i++);
		if (i != height) break;
	}
	return { left + 1, right - 1 };
}

int main() {
	scanf("%d", &n);

	while (n-- && scanf("%d %d", &a, &b)) {
		pos.push_back({ a, b });
		pos.push_back({a + 9, b});
		pos.push_back({ a, b + 9 });
		pos.push_back({ a + 9, b + 9 });
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++) map[a + i][b + j]++;
	}
	for (int i = 0; i < pos.size(); i++) {
		int x = pos[i].first;
		int y = pos[i].second;
		int width = getWidth(x, y, map[x][y]);
		int height = getHeight(x, y, map[x][y]);
		pair<int, int> pos1 = getMaxHeightPos(x, y, width);
		pair<int, int> pos2 = getMaxWidthPos(pos1.first, y, pos1.second - pos1.first + 1);
		pair<int, int> pos3 = getMaxWidthPos(x, y, height);
		pair<int, int> pos4 = getMaxHeightPos(x, pos3.first, pos3.second - pos3.first + 1);
		int area1 = (pos1.second - pos1.first + 1) * (pos2.second - pos2.first + 1);
		int area2 = (pos3.second - pos3.first + 1) * (pos4.second - pos4.first + 1);
		ans = max({ ans, area1, area2 });
	}
	printf("%d", ans);
}

/*
먼저 도화지로 사용될 배열을 0으로 초기화해둔 뒤, 각 색종이가 차지하는 범위를 1씩 증가시켜줍니다.
붙여지는 각 색종이의 네 개의 꼭짓점 좌표는 가장 큰 검은색 직사각형의 꼭짓점 후보군이 될 수 있습니다.
각 꼭짓점을 돌면서 각 꼭짓점에서 같은 값(색종이가 중복해서 차지하는 값)을 가지는 직사각형의 길이와 높이를 구해줍니다.
그렇게 구한 길이와 높이로 다음 두 가지의 면적을 구해줍니다.
구한 높이를 기준으로 색종이가 차지하는 범위의 길이를 최대로 확장했을 때, 이것의 길이를 기준으로 높이를 최대한 확장했을 때의 직사각형 면적을 구해줍니다.
구한 길이를 기준으로 색종이가 차지하는 범위의 높이를 최대로 확장했을 때, 이것의 높이를 기준으로 길이를 최대한 확장했을 때의 직사각형 면적을 구해줍니다.
두 개의 면적 중 최댓값으로 정답을 업데이트해줍니다.
*/