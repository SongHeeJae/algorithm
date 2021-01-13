#include <cstdio>
#include <cmath>

void fun(int x, int from, int to, int help) {
	if (x == 1) {
		printf("%d %d\n", from, to);
		return;
	}
	fun(x - 1, from, help, to);
	printf("%d %d\n", from, to);
	fun(x - 1, help, to, from);
}

int main() {
	int a;
	scanf("%d", &a);
	printf("%d\n", (int)pow(2, a) - 1);
	fun(a, 1, 3, 2);
}