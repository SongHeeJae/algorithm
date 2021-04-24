#include <cstdio>

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int main() {
	int a, b;
	scanf("%d:%d", &a, &b);
	int res = gcd(a, b);
	printf("%d:%d", a / res, b / res);
}

/*
두 수의 최대공약수로 각 수를 나누었습니다.
*/