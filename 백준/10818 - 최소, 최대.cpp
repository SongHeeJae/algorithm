#include <cstdio>
int main()
{
	int n=-1000001, m=1000001, a, b;
	scanf("%d", &a);
	while (a-- && scanf("%d", &b))
	{
		if (n < b) n = b;
		if (m > b) m = b;
	}
	printf("%d %d", m, n);
}
