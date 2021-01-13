#include <cstdio>
int main() {
	int t, h, w, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &h, &w, &n);
		printf("%d%02d\n", n % h ? n % h : h, n % h ? n/h + 1 : n / h);
	}
}