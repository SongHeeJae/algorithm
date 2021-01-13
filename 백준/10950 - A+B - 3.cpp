#include <cstdio>
int main()
{
	int a, x, y;
	scanf("%d", &a);
	while (a--)
	{
		scanf("%d %d", &x, &y);
		printf("%d\n",x + y);
	}
}