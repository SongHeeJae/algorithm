#include <cstdio>
int a, b, c = 1;
int main() {
	scanf("%d %d", &a, &b);
	while (a < b) {
		if (b % 2 == 0) b /= 2;
		else if (b % 10 == 1) b /= 10;
		else break;
		c++;
	}
	printf("%d", a == b ? c : -1);
}

/*
각 연산을 역으로 수행하며 B를 A로 변환시켜주었습니다.
b가 짝수라면, 2로 나누어줍니다. (1번 연산) 
b의 일의 자리 숫자가 1이라면, 10으로 나누어줍니다. (2번 연산)
두 연산을 취할 수 없는 상태라면, B는 A가 될 수 없습니다.
*/