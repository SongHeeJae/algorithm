#include <iostream>
#include <algorithm>
#define INF 2147483647
int main() {
	int n, m, a, i, oven[300001] = { INF, };
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n && scanf("%d", &a); i++) oven[i] = std::min(oven[i - 1], a);
	for (i = n + 1; m-- && scanf("%d", &a);)
		while (--i >= 0 && a > oven[i]);
	printf("%d", std::max(i, 0));
}
