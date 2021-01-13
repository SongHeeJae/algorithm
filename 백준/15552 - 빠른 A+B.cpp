#include <iostream>
int main()
{
	int num, x, y;
	scanf("%d", &num);
	while (num--)
	{
		scanf("%d %d", &x, &y);
		printf("%d\n", x + y);
	}
}