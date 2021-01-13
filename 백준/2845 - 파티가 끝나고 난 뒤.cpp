#include <cstdio>
int main()
{
	int l, p, s;
	scanf("%d %d", &l, &p);
	for (s = l *p, l = 5; l-- && scanf("%d", &p); printf("%d ", p - s));
}