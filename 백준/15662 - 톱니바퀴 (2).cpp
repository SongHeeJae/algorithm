#include <cstdio>
int t, k, n, m, s = 0;
char NS[1000][9], left[1000];
void rotate(int a, int b, int c) {
	if (a > 0 && a - 1 != c && NS[a - 1][(left[a - 1] + 4) % 8] != NS[a][left[a]]) rotate(a - 1, -1 * b, a);
	if (a < t - 1 && a + 1 != c && NS[a + 1][left[a + 1]] != NS[a][(left[a] + 4) % 8]) rotate(a + 1, -1 * b, a);
	left[a] = b == 1 ? (left[a] + 7) % 8 : (left[a] + 1) % 8;
}
int main() {
	scanf("%d", &t);
	for (int i = 0; i < t && scanf("%s", NS[i]); left[i] = 6, i++);
	scanf("%d", &k);
	while (k-- && scanf("%d %d", &n, &m)) rotate(n - 1, m, n - 1);
	for (int i = 0; i < t; i++) s += NS[i][(left[i] + 2) % 8] - '0';
	printf("%d", s);
}

/*
각 톱니바퀴의 가장 왼쪽 톱니의 위치를 기억하고, 이를 회전해주며 업데이트해줬습니다.
*/