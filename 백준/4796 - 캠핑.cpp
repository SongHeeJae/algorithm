#include <cstdio>
int l, p, v, i = 1;
int main() {
	while (scanf("%d %d %d", &l, &p, &v) && l)
		printf("Case %d: %d\n", i++, (v / p) * l + (v % p > l ? l : v % p));
}