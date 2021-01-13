#include <cstdio>
int main()
{
	int d[46] = { 0, 1, }, k;
	scanf("%d", &k);
	for (int i = 2; i <= k; i++) d[i] = d[i - 1] + d[i - 2];
	if (k == 0) printf("1 0");
	else printf("%d %d", d[k - 1], d[k]);
}