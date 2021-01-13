#include <cstdio>
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n-i; j++) printf(" ");
		for (int j = 0; j < i * 2 + 1; j++) printf("*");
		printf("\n");
	}
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j <= i; j++) printf(" ");
		for (int j = 0; j < (n - i - 2) * 2 + 1; j++) printf("*");
		printf("\n");
	}
}