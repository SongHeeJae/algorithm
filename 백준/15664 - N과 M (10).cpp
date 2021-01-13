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
	int p = -1;
	for (int i = idx; i < n; i++) {
		if (v[i] || p == a[i]) continue;
		v[i] = 1;
		b[c] = a[i];
		f(i, c + 1);
		v[i] = 0;
		p = a[i];
	}
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	std::sort(a, a + n);
	f(0, 0);
}