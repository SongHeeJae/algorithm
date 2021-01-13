#include <cstdio>
int main()
{
	int a, b;
	while (scanf("%d %d", &a, &b))
	{
		if (!a) break;
		if (!(a % b)) puts("multiple");
		else if (!(b % a)) puts("factor");
		else puts("neither");
	}
}