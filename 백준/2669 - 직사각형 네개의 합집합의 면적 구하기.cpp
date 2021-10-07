#include <cstdio>
#define MAX 101

int x1, y1, x2, y2, ans = 0, map[MAX][MAX] = { 0 };
int main() {
	for (int i = 0; i < 4; i++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for (int j = x1; j < x2; j++) {
			for (int k = y1; k < y2; k++) {
				map[j][k] = 1;
			}
		}
	}
	for (int i = 1; i < MAX; i++) {
		for (int j = 1; j < MAX; j++) {
			ans += map[i][j];
		}
	}
	printf("%d", ans);
}

/*
2차원 배열에서 직사각형의 위치를 표시하고, 그 개수를 구해주었습니다.
*/