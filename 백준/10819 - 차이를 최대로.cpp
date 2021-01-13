#include <iostream>
#include <algorithm>
#include <cmath>
int n, a[8], b[8], c[8], v[8] = { 0 }, ans = -1;
void cal() {
	int s = 0;
	for (int i = 0; i < n-1; i++) s += abs(c[b[i]] - c[b[i + 1]]);
	ans = std::max(s, ans);
}
void fun(int cnt) {
	if (cnt == n) {
		cal();
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
	for (int i = 0; i < n; i++) a[i] = i;
	for (int i = 0; i < n; i++) scanf("%d", &c[i]);
	fun(0);
	printf("%d", ans);
}