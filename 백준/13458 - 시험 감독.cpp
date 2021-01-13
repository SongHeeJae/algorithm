#include <cstdio>
int n, a[1000000], b;
double c;
long long int s;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d %lf", &b, &c);
	s = n;
	for (int i = 0; i < n; i++) {
		a[i] -= b;
		if (a[i] > 0) s += (int)(a[i] / c + 0.999999);
	}
	printf("%lld", s);
}