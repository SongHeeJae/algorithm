#include <cstdio>
#define MAX 1003001 + 1

int n, val[8];
bool notPrime[MAX] = { false };

bool isPalindrome(int num) {
	int idx = 0;
	while (num != 0) {
		val[idx++] = num % 10;
		num /= 10;
	}
	for (int i = 0; i < idx / 2; i++) {
		if (val[i] != val[idx - i - 1]) return false;
	}
	return true;
}

int main() {
	scanf("%d", &n);
	for (int i = 2; ; i++) {
		if (notPrime[i]) continue;
		if (i >= n && isPalindrome(i)) {
			printf("%d", i);
			break;
		}
		for (int j = i + i; j < MAX; j+=i) {
			notPrime[j] = true;
		}
	}
}

/*
에라토스테네스의 체 방식으로 순차적으로 소수를 구하면서, 그 값이 n보다 크거나 같을 때 팰린드롬인지 검사해주었습니다.
입력 값이 N = 1,000,000일 때,
정답은 1003001이란 값을 가지므로, 그 범위까지만 수행해주었습니다.
*/