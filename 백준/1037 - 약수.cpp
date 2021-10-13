#include <cstdio>
int main() {
	int m, n, a, mx, mn;
	scanf("%d %d", &m, &a);
	mx = mn = a;
	while (--m) {
		scanf("%d", &a);
		if (a < mn) mn = a;
		if (a > mx) mx = a;
	}
	printf("%d", mx * mn);
}