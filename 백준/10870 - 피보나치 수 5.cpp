#include <cstdio>

int fun(int x) {
	if (x < 2) return x;
	else return fun(x-1) + fun(x-2);
}

int main() {
	int a;
	scanf("%d", &a);
	printf("%d", fun(a));
}