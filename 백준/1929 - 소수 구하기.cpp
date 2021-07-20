#include <cstdio>

int m, n;
bool chk[1000001] = { false };

int main() {
	chk[1] = true;
	scanf("%d %d", &m, &n);
	for (int i = 2; i <= n; i++) {
		if (chk[i]) continue;
		for (int j = i + i; j <= n; j += i) {
			chk[j] = true;
		}
	}
	for (int i = m; i <= n; i++) {
		if (!chk[i]) printf("%d\n", i);
	}
}