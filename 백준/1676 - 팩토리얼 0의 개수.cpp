#include <cstdio>
int main() {
	int n, c = 0;
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		int ii = i;
		while (ii % 5 == 0) {
			ii /= 5;
			c++;
		}
	}
	printf("%d", c);
}

/*
뒤에 0이란 숫자는 2 * 5로 인해 하나가 붙게 됩니다.
N!을 소인수 분해했을 때, 2의 개수와 5의 개수 중에 더 적은 개수가 0의 개수가 됩니다.
2의 개수가 더 많이 나올리는 없으니 5의 개수가 0의 개수입니다.
*/