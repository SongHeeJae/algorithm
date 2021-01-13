#include <cstdio>

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n*2 - 1;i++) {
		for (int j = 0; j < n * 2; j++)
			if (i < n) j <= i || j >= n * 2 - 1 - i ? printf("*") : printf(" ");
			else j < n * 2 - 1 - i || j > i ? printf("*") : printf(" ");
		printf("\n");
	}
}