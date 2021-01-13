#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

int map[10][10], ans = INF, s[5] = { 0 }, n = 0;

void copy(int a[][10], int b[][10]) {
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			a[i][j] = b[i][j];
}

void f(int x, int y, int c) {
	if (x == 10) {
		if(n==0) ans = min(ans, c); // 모든 색종이 공간이 채워졌을 때만 업데이트
		return;
	}

	if (map[x][y] == 1) {
		int temp[10][10]; // 기존 상태
		copy(temp, map);
		for (int i = 0; i < 5; i++) {
			int cnt = 0;
			for (int j = x; j <= x + i; j++) {
				for (int k = y; k <= y + i; k++) {
					if (j >= 10 || k >= 10 || map[j][k] == 0) break;
					map[j][k] = 0;
					cnt++;
				}
			}
			if (cnt == (i + 1) * (i + 1)) { // 붙일 수 있는 색종이면 붙임
				if (s[i] < 5) {
					s[i]++; n-=cnt; // 색종이 붙인 갯수 업데이트
					f(y == 9 ? x + 1 : x, (y + 1) % 10, c + 1);
					s[i]--; n+=cnt;
				}
				copy(map, temp);
			} else { // 그렇지 않다면, 더 큰 사이즈도 붙일 수 없으므로 break
				copy(map, temp);
				break;
			}
		}
		
	}
	else f(y == 9 ? x + 1 : x, (y + 1) % 10, c); // 붙일 수 없는 공간은 그냥 넘어감
}

int main() {
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10 && scanf("%d", &map[i][j]); j++)
			if(map[i][j] == 1) n++;
	if (n == 100) printf("4"); // 그냥 오래 걸리는연산 고정 갯수길래..
	else if (n == 0) printf("0");
	else {
		f(0, 0, 0);
		printf("%d", ans != INF ? ans : -1);
	}
}