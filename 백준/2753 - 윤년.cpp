#include <cstdio>
int main()
{
	int a;
	scanf("%d", &a);
	(!(a % 4) && (a % 100)) || !(a % 400) ? puts("1") : puts("0");
}