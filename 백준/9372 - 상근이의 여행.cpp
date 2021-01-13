#include <iostream>
int main()
{
	int t, n, m, a, b;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		while (m--) scanf("%d %d", &a, &b);
		printf("%d\n", n-1);
	}
}