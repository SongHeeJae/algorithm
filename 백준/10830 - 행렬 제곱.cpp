#include <cstdio>
int n, i, j, k;
long long int b;
void cal(int a1[][5], int a2[][5]) {
	int c[5][5] = {0};
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			for (k = 0; k < n; k++) c[i][j] += a1[i][k] * a2[k][j];
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) a1[i][j] = c[i][j] % 1000;
}
int main() {
	int a[5][5], aa[5][5] = {0};
	scanf("%d %lld", &n, &b);
	for (i = 0; i < n; aa[i][i] = 1, i++)
		for (j = 0; j < n && scanf("%d", &a[i][j]); j++);
	while (b) b % 2 ? (cal(aa, a), b--) : (cal(a, a), b /= 2);
	for (i = 0; i < n; printf("\n"), i++)
		for (j = 0; j < n; j++) printf("%d ", aa[i][j] % 1000);
}