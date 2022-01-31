#include <cstdio>
int c = 1;
char s[6];
int main() {
	scanf("%s", s + 1);
	for (int i = 1; s[i]; i++)
		c *= (s[i] == 'c' ? 26 : 10) - (s[i] == s[i - 1]);
	printf("%d", c);
}

/*
c 또는 d가 연속되는 경우에는, 25개 또는 9개를 곱해주면 되었습니다.
*/