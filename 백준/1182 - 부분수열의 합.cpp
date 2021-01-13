#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;
int n, s, a[20], ans = 0;
void f(int idx, int sum, int c) {
	if (c == n) return;
	for (int i = idx; i < n; i++) {
		int ns = sum + a[i];
		if (s == ns) ans++;
		f(i + 1, ns, c + 1);
	}
}

int main() {
	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	f(0, 0, 0);
	printf("%d", ans);
}