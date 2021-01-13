#include <cstdio>
int n, s = 0, c = 1, i;
int main() {
	scanf("%d", &n);
	for (i = 10; i <= n; i *= 10) s += c++ * i/10*9;
	printf("%d", s + c * (n - i / 10 + 1));
}