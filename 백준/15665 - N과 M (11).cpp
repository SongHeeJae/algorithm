#include <iostream>
#include <algorithm>
int a[8], b[8], n, m;
void f(int c) {
	if (c == m) {
		for (int i = 0; i < m; i++)
			printf("%d ", b[i]);
		printf("\n");
		return;
	}
	int p = -1;
	for (int i = 0; i < n; i++) {
		if (p == a[i]) continue;
		b[c] = a[i];
		f(c + 1);
		p = a[i];
	}
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	std::sort(a, a + n);
	f(0);
}