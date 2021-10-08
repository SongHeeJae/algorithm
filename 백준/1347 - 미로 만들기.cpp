#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 50
using namespace std;

int dx[] = {1, 0, -1, 0}; // 남동북서
int dy[] = {0, 1, 0, -1};

int n, tlx = MAX, tly = MAX, brx = MAX, bry = MAX;
int x = MAX, y = MAX, dir = 0;
char op, map[MAX * 2 + 1][MAX * 2 + 1];
int main() {
	memset(map, '#', sizeof(map));
	map[50][50] = '.';
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf(" %c", &op);
		if (op == 'R') dir = (dir + 3) % 4;
		else if (op == 'L') dir = (dir + 1) % 4;
		else {
			x += dx[dir];
			y += dy[dir];
			tlx = min(tlx, x);
			tly = min(tly, y);
			brx = max(brx, x);
			bry = max(bry, y);
			map[x][y] = '.';
		}
	}
	for (int i = tlx; i <= brx; i++) {
		for (int j = tly; j <= bry; j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
}

/*
50개의 이동을 감당할 수 있는 충분한 크기의 배열을 잡고, 모두 '#'으로 초기화해줍니다.
배열의 정중앙을 시작점으로 잡고, 주어지는 연산으로 이동을 수행해주었습니다.
이동했던 지점들은 모두 '.' 으로 바꿔주면서, 그 지점들의 가장 북서 좌표와 남동 좌표를 기억해주었습니다.
북서, 남동 좌표 내의 지점들을 출력해주면 됩니다.
*/