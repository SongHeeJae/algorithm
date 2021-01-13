#include <cstdio>

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int lcm(int a, int b, int c) {
	return a * b / c;
}

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	int res1 = gcd(a > b ? a : b, a > b ? b : a);
	int res2 = lcm(a, b, res1);
	printf("%d\n%d", res1, res2);

}