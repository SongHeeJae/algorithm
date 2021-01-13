#include <cstdio>

int fun(int x) {
	if (x < 2) return 1;
	else return x * fun(x - 1);
}

int main() {
	int a;
	scanf("%d", &a);
	printf("%d", fun(a));
}