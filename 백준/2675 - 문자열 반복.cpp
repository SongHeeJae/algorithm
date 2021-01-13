#include <iostream>
int main()
{
	int n, m, l;
	char c;
	for (scanf("%d", &n); n--; printf("\n"))
	{
		for (scanf("%d", &m), getchar();(c = getchar()) != '\n';)
			for (l = m; l--;) putchar(c);
	}
}