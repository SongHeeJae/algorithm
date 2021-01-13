#include <iostream>
int main()
{
	int s = 0, n;
	for (int i = 5; i-- && scanf("%d", &n); s += n > 39 ? n : 40);
	printf("%d", s / 5);
}