#include <cstdio>

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n*2 - 1;i++) {
		for (int j = 0; j < n; j++)
			if (i < n) j >= n-i-1 ? printf("*") : printf(" ");
			else j > i-n? printf("*") : printf(" ");
		printf("\n");
	}
}