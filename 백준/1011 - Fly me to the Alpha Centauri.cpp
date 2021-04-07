#include <cstdio>
#include <cmath>
long long int t, a, b;
int main() {
	scanf("%d", &t);
	while (t-- && scanf("%d %d", &a, &b)) {
		long long int val = sqrt(b-a);
		if (val * val == b - a)
			printf("%lld\n", 2 * val - 1);
		else if (val * val < b - a && b - a <= val * val + val)
			printf("%lld\n", 2 * val);
		else
			printf("%lld\n", 2 * val + 1);
	}
}