#include <cstdio>
int main() {
	int a, ans = 0;
	for (int i = 5; i--;) {
		scanf("%d", &a);
		ans += a * a;
	}
	printf("%d", ans % 10);
}