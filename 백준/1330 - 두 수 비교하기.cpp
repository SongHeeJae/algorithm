#include <cstdio>
int main()
{
	int a, b, c;
	scanf("%d %d", &a, &b);
	a > b ? puts(">") : (a == b ? puts("==") : puts("<"));
}