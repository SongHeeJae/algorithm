#include <iostream>
int main()
{
	int n, c;
	scanf("%d", &n);
	if (n > 99)
	{
		c = 99;
		for (int i = 100; i <= n; i++) if (i / 100 - i / 10 % 10 == i / 10 % 10 - i % 10) c++;
	}
	else c = n;
	printf("%d", c);
}