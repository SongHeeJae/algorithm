#include <cstdio>
int a[3], b[3], y = 0;
int main() {
	scanf("%d %d %d", &a[0], &a[1], &a[2]);
	for (; b[0] != a[0] || b[1] != a[1] || b[2] != a[2];y++) {
		b[0] = b[0] % 15 + 1;
		b[1] = b[1] % 28 + 1;
		b[2] = b[2] % 19 + 1;
	}
	printf("%d", y);
}