#include <iostream>

int main() {
	int max = -1, n = 4, a, b, c = 0;
	while (n--) {
		scanf("%d %d", &a, &b);
		c += b - a;
		max = c > max ? c : max;
	}
	printf("%d\n", max);
}