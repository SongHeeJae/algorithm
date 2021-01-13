#include <cstdio>

int main() {
	int a, b, n;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &a);
		getchar();
		scanf("%d", &b);
		printf("%d\n", a +b);
	}
}