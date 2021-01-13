#include <iostream>
int main()
{
	int n, a, d[11] = { 0, 1, 2, 4};
	for (int i = 4; i <= 10; i++) d[i] = d[i - 1] + d[i - 2] + d[i - 3];
	scanf("%d", &n);
	while (n-- && scanf("%d", &a)) printf("%d\n", d[a]);
}