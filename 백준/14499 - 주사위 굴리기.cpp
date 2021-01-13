#include <iostream>
#include <vector>
using namespace std;
int s[] = { 0, 0, 0, 0, 0, 0 }; // 밑, 북, 동, 서, 남, 윗
int dx[] = {0, 0, -1, 1}; // 동서북남
int dy[] = {1, -1, 0, 0};

void changeDice(int a) {
	int temp = s[0];
	if (a == 1) {
		s[0] = s[3];
		s[3] = s[5];
		s[5] = s[2];
		s[2] = temp;
	}
	else if (a == 2) {
		s[0] = s[2];
		s[2] = s[5];
		s[5] = s[3];
		s[3] = temp;
	}
	else if (a == 3) {
		s[0] = s[4];
		s[4] = s[5];
		s[5] = s[1];
		s[1] = temp;
	}
	else {
		s[0] = s[1];
		s[1] = s[5];
		s[5] = s[4];
		s[4] = temp;
	}
}

void moveDice(vector<vector<int>>& map, int a, int& x, int& y) {
	int n = map.size();
	int m = map[0].size();
	int xx = x + dx[a - 1];
	int yy = y + dy[a - 1];
	if (xx < 0 || yy < 0 || xx >= n || yy >= m) return;
	x = xx;
	y = yy;
	changeDice(a);
	if (map[x][y]) {
		s[0] = map[x][y];
		map[x][y] = 0;
	}
	else map[x][y] = s[0];
	printf("%d\n", s[5]);
}

int main()
{
	int n, m, x, y, k, a;
	scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);
	vector<vector<int>> map(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &map[i][j]);
	while (k-- && scanf("%d", &a)) moveDice(map, a, x, y);
}