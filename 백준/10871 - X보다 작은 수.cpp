#include <iostream>
int main()
{
	int a, b, c;
	scanf("%d %d", &a, &b);
	while (a-- && scanf("%d", &c)) if (c < b) printf("%d ", c);
}