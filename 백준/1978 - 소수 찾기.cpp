#include <cstdio>

int n, a, cnt = 0;
bool chk[1001] = { false };

int main() {
	chk[1] = true;
	for (int i = 2; i <= 1000; i++) {
		if (chk[i]) continue;
		for (int j = i + i; j <= 1000; j += i) {
			chk[j] = true;
		}
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		if (!chk[a]) cnt++;
	}
	printf("%d", cnt);
}