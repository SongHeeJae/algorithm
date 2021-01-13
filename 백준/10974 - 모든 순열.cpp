#include <iostream>
#include <algorithm>
int n, a[8], b[8], v[8] = { 0 };
void fun(int cnt) {
	if (cnt == n) {
		for (int i = 0; i < n; i++) printf("%d ", b[i]);
		printf("\n");
		return;
	}
	for (int i = 0; i < n; i++) {
		if (v[i]) continue;
		v[i] = 1;
		b[cnt] = a[i];
		fun(cnt + 1);
		v[i] = 0;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) a[i] = i + 1;
	fun(0);
}