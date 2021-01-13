#include <iostream>
#include <vector>
using std::vector;
int t, n;
bool prime[10001] = {false,};
vector<int> primes;

void initPrimeNumbers() {
	for (int i = 2; i <= 10000; i++) {
		if (prime[i]) continue;
		for (int j = i*2; j <= 10000; j += i) prime[j] = true;
	}
	for(int i=2; i<=10000; i++)
		if(!prime[i]) primes.push_back(i);
}

int main() {
	initPrimeNumbers();
	scanf("%d", &t);
	while (t--) {
		int a=0, b=9999;
		scanf("%d", &n);
		for (int i = 0; i < primes.size(); i++) {
			if (primes[i] > n) break;
			for (int j = i; j < primes.size(); j++) {
				if (primes[j] > n) break;
				if (n == primes[i] + primes[j] && b-a > primes[j]-primes[i]) {
					a = primes[i];
					b = primes[j];
				}
			}
		}
		printf("%d %d\n", a, b);
	}
}