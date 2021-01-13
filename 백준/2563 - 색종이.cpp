#include <cstdio>
int main() {
	int n, a, b, m[100][100] = { 0, }, s = 0, i, j;
	scanf("%d", &n);
	while (n-- && scanf("%d %d", &a, &b))
		for (i = a; i < a + 10; i++)
			for (j = b; j < b + 10; m[i][j++] = 1)
				if (!m[i][j]) s++;
	printf("%d\n", s);
}
