#include <cstdio>
int main() {
	int n;
	long long int s = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) s += n * i + i;
	printf("%lld\n", s);
}