#include <cstdio>
int main() {
	int n, b[1023];
	scanf("%d", &n);
	int num = (1 << n) - 1;
	for (int i = 0; i < num; i++) scanf("%d", &b[i]);
	while (n--) {
		int cnt = (1 << n + 1);
		for (int i = (cnt - 1) / 2; i < num; i += cnt) printf("%d ", b[i]);
		printf("\n");
	}
}