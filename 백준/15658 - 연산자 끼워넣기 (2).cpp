#include <iostream>
#include <algorithm>
using namespace std;
int n, a[11], b[4], m1 = -2e9, m2 = 2e9;
void f(int res, int c) {
	if (c == n) {
		m1 = max(res, m1);
		m2 = min(res, m2);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (b[i] == 0) continue;
		b[i]--;
		if (i == 0) f(res + a[c], c + 1);
		else if (i == 1) f(res - a[c], c + 1);
		else if (i == 2) f(res * a[c], c + 1);
		else f(res / a[c], c + 1);
		b[i]++;
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < 4; i++) scanf("%d", &b[i]);
	f(a[0], 1);
	printf("%d\n%d", m1, m2);
}