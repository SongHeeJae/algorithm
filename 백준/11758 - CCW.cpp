#include <cstdio>

int p[3][2];

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
	return (x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1);
}

int main() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			scanf("%d", &p[i][j]);
		}
	}
	int res = ccw(p[0][0], p[0][1], p[1][0], p[1][1], p[2][0], p[2][1]);
	if (res > 0) printf("1");
	else if (res < 0) printf("-1");
	else printf("0");
}

/*
ccw의 결과가 음수이면 시계 방향, 양수이면 반시계 방향을 나타냅니다.
*/