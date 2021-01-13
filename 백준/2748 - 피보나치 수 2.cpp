#include <iostream>

int main() {
	long long int f[91] = { 0 };
	int n;
	f[1] = 1;
	for (int i = 2; i <= 90; i++) f[i] = f[i - 1] + f[i - 2];
	scanf("%d", &n);
	printf("%lld\n", f[n]);
}