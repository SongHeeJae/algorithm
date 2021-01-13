#include <cstdio>
int main()
{
	int n, l;
	scanf("%d %d", &n, &l);
	for (int i = l; i <= 100; i++) {
		int j = (i - 1) * i / 2;
		if ((n - j) % i == 0 && (n - j) / i >= 0) {
			int x = (n - j) / i;
			for (int k = 0; k < i; k++) printf("%d ", x + k);
			return 0;
		}
	}
	printf("-1\n");
}