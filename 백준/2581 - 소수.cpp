#include <cstdio>
#define MAX 10001

int m, n, sum = 0, mn = MAX;
bool notPrime[MAX] = { false };

int main() {
	notPrime[1] = true;
	for (int i = 2; i < MAX; i++) {
		if (notPrime[i]) continue;
		for (int j = i + i; j < MAX; j += i)
			notPrime[j] = true;
	}
	scanf("%d %d", &m, &n);
	for (int i = m; i <= n; i++) {
		if (!notPrime[i]) {
			sum += i;
			if (mn == MAX) mn = i;
		}
	}
	if (sum == 0) printf("-1");
	else printf("%d\n%d", sum, mn);
}

/*
소수를 미리 구해놓고, 범위에 해당하는 값을 구해주었습니다
*/