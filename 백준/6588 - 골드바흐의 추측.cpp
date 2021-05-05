#include <cstdio>
#define MAX 1000000

int n, a, b;
bool primes[MAX + 1] = { false };

void initPrimes() {
	for (int i = 2; i <= MAX; i++) {
		if (primes[i]) continue;
		for (int j = i + i; j <= MAX; j += i) {
			primes[j] = true;
		}
	}
}


int main() {
	initPrimes();
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		a = b = -1;
		for (int i = 3; n - i > 0; i++) {
			if (!primes[i] && !primes[n - i]) {
				a = i, b = n - i;
				break;
			}
		}
		if (a == -1) printf("Goldbach's conjecture is wrong.\n");
		else printf("%d = %d + %d\n", n, a, b);
	}
}

/*
모든 소수를 구해둔 뒤, 두 소수의 합이 n을 만족하는지 구해주었습니다.
*/