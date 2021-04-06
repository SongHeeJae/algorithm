#include <cstdio>
int cnt = 0, ans = 0, ch, pch;
int main() {
	while ((ch=getchar()) != '\n') {
		if (ch == '(') cnt++;
		else cnt--, ans += pch == '(' ? cnt : 1;
		pch = ch;
	}
	printf("%d", ans);
}

/*
레이저일 때는,
ans += 쇠막대기의 개수;

쇠막대기의 끝일 때는,
쇠막대기의 개수 -= 1;
ans += 지금 분리된 쇠막대기 1개;
*/