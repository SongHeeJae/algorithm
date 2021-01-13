#include <cstdio>
int n, c = 0, ans = 666, p = 666, a;
void f(int s) {
	if (c + s + 1 > n) {
		for (int i = 0; i < s; i++) {
			p = ans;
			c++;
			if (n == c) return;
			ans++;
		}
	}
	else {
		ans += s;
		c += s;
	}
	a = 0;
}
int main() {
	scanf("%d", &n);
	while (n != c) {
		for (a = ans; a != 0; a /= 10)
			if (a % 1000 == 666) {
				if (ans % 1000 == 1) f(999);
				else if (ans % 100 == 1) f(99);
				else if (ans % 10 == 1) f(9);
				else c++;
				p = ans;
				break;
			}
		if (ans % 1000 == 666 && ans % 10000 != 5666 && ans % 10000 != 6666)
			ans += 1000;
		else ans++;
	}
	printf("%d", p);
}