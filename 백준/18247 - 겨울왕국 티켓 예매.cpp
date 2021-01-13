#include <iostream>
int main() {
	int t, n, m, i = 'L' - 'A' + 1;
	scanf("%d", &t);
	while (t-- && scanf("%d %d", &n, &m)) 
		printf("%d\n", n < i || m < 4 ? -1 : m * (i - 1) + 4 );
}
