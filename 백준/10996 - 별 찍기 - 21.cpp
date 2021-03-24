#include <cstdio>
int n;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n * 2; i++, printf("\n"))
		for (int j = 0; j < n; j++) printf("%c", (i + j) % 2 ? ' ' : '*');
}