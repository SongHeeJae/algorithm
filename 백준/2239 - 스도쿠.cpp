#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool fillNumber(vector<vector<int>>& map, int x, int y, int a) {
	int sx = x / 3 * 3;
	int sy = y / 3 * 3;
	for (int i = sx; i < sx + 3; i++)
		for (int j = sy; j < sy + 3; j++)
			if (map[i][j] == a) return false;
	for (int i = 0; i < 9; i++)
		if (map[x][i] == a) return false;
	for (int i = 0; i < 9; i++)
		if (map[i][y] == a) return false;
	return true;
}

void sdoku(vector<vector<int>>& map, int x, int y) {
	if (x >= 9 ) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) printf("%d", map[i][j]);
			printf("\n");
		}
		exit(0);
	}
	int nx = y == 8 ? x + 1 : x;
	int ny = (y + 1) % 9;
	if (map[x][y] == 0)
		for (int i = 1; i <= 9; i++) {
			if (fillNumber(map, x, y, i)) {
				map[x][y] = i;
				sdoku(map, nx, ny);
				map[x][y] = 0;
			}
		}
	else sdoku(map, nx, ny);	
}

int main()
{
	vector<vector<int>> map(9, vector<int>(9));
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) map[i][j] = getchar() - '0';
		getchar();
	}
	sdoku(map, 0, 0);
}