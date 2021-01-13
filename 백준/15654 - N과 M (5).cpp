#include <iostream>
#include <algorithm>

int n, m, a[8], b[8], v[8] = { 0 };
void f(int c) {
	if (c == m) {
		for (int i = 0; i < m; i++)
			printf("%d ", b[i]);
		printf("\n");
		return;
	}
	for (int i = 0; i < n; i++) {
		if (v[i]) continue;
		b[c] = a[i];
		v[i] = 1;
		f(c + 1);
		v[i] = 0;
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	std::sort(a, a + n);
	f(0);
}