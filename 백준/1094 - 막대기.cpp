#include <cstdio>
int main() {
	int x, c = 0;
	scanf("%d", &x);
	for (; x; x /= 2) c += x & 1;
	printf("%d\n", c);
}
