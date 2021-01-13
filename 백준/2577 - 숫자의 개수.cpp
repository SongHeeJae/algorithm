#include <iostream>
int main()
{
	int n, s = 1, d[10] = { 0, };
	for (int i=3;i--;s*=n) scanf("%d", &n);
	for (; s != 0; d[s % 10]++, s /= 10);
	for (int i = 0; i < 10; i++) printf("%d\n", d[i]);
}