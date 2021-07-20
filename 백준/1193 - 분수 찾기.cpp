#include <cstdio>
int x, c = 1, s = 1;
int main() {
	scanf("%d", &x);
	while (s <= x) s += c++;
	if (c % 2) printf("%d/%d", x + c - s, s - x);
	else printf("%d/%d", s - x, x + c - s);
}

/*
몇 번째 대각선인지 구한 뒤, 행 번호와 열 번호를 구해주었습니다.
*/