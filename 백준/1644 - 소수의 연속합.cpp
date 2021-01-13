#include <iostream>
#include <vector>
using namespace std;

vector<int> primes;
int n, c = 0;

void setPrimes(int max) {
	vector<int> num(max + 1, 1);
	for (int i = 2; i < num.size(); i++) {
		if (num[i] == 0) continue;
		primes.push_back(i);
		for (int j = i * 2; j < num.size(); j+=i)
			num[j] = 0;
	}
}

int main() {
	scanf("%d", &n);
	setPrimes(n);
	for (int i = 0; i < primes.size(); i++) {
		int sum = 0;
		for (int j = i; sum < n && j<primes.size(); j++) {
			sum += primes[j];
			if (sum == n) {
				c++;
				break;
			}
		}
	}
	printf("%d", c);
}

/*
에라토스테네스의 체를 이용하여 n까지의 모든 소수를 구해놓고, 연속하는 소수들에 대하여 덧셈을 진행하였습니다.
*/