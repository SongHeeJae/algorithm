#include <iostream>
#include <algorithm>
int a[8], b[8], n, m, v[8] = { 0 };
void f(int idx, int c) {
	if (c == m) {
		for (int i = 0; i < m; i++)
			printf("%d ", b[i]);
		printf("\n");
		return;
	}
	for (int i = idx; i < n; i++) {
		b[c] = a[i];
		f(i, c + 1);
	}
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	std::sort(a, a + n);
	f(0, 0);
}