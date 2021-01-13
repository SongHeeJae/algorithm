#include <cstdio>
int main()
{
	int l, n, a, b, m11 = -1, m12, m21 = -1, m22, c;
	bool cake[1001] = { false, };
	scanf("%d %d", &l, &n);
	for (int i = 1; i <= n && scanf("%d %d", &a, &b); i++) {
		if (b - a + 1 > m11) {
			m11 = b - a + 1;
			m12 = i;
		}
		c = 0;
		for (int j = a; j <= b; j++) {
			if (!cake[j]) c++;
			cake[j] = true;
		}
		if (c > m21) {
			m21 = c;
			m22 = i;
		}
	}
	printf("%d\n%d", m12, m22);
}