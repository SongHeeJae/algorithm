#include <iostream>
#include <vector>
using namespace std;

bool promising(int map[][9], int x, int y) {

	
	for (int i = 0; i < 9; i++) // 가로 검사 x 고정.
		if (i != y && map[x][i] == map[x][y]) return false;

	for (int i = 0; i < 9; i++) // 세로 검사 y 고정.
		if (i != x && map[i][y] == map[x][y]) return false;

	for (int i = x / 3 * 3; i < x / 3 * 3 + 3; i++) // 3*3 박스 검사.
		for (int j = y / 3 * 3; j < y / 3 * 3 + 3; j++)
			if (i != x && j != y && map[x][y] == map[i][j]) return false;
	return true;
}

void printAnswer(vector<pair<int, int>>& pos, int map[][9], int c) {
	
	if (c == pos.size()) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) printf("%d ", map[i][j]);
			printf("\n");
		}
		exit(0);
	}
	int x = pos[c].first;
	int y = pos[c].second;
	for (int i = 1; i <= 9; i++) {
		map[x][y] = i;
		if (promising(map, x, y)) printAnswer(pos, map, c + 1);
	}
	map[x][y] = 0;
	
}

int main() {
	int map[9][9];
	vector<pair<int, int>> pos;
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0) pos.push_back(make_pair(i, j));
		}
	printAnswer(pos, map, 0);
}