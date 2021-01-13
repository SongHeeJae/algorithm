#include <cstdio>
int t, m, n, x, y, a, b, max, ans;
int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int lcm(int a, int b) {
	return a * b / gcd(a, b);
}
int main() {
	scanf("%d", &t);
	while (t-- && scanf("%d %d %d %d", &m, &n, &x, &y)) {
		a = x;
		b = (x - 1) % n + 1;
		max = lcm(m, n);
		ans = -1;
		while (a < max) { 
			if (b == y) { ans = a; break; }
			a += m;
			b = (b + m - 1) % n + 1;
		}
		printf("%d\n", ans);
	}
}

/*
문제에서 M=10, N=12 일 때, <10:12>는 마지막인 60번째 해를 나타낸다고 합니다.
따라서 연도는 M과 N의 최소공배수를 넘길 수 없습니다. 그 경우에는 유효하지 않으므로 -1로 나타내줍니다.
처음에 1씩 증가시키면서 일치할때 까지 반복을 해줬는데, 그럴 경우 시간초과가 납니다.
불필요한 반복 횟수를 줄이기 위해 x와 y중 하나를 기준으로 잡고, 그 값을 고정으로 해서 다른 값의 연도를 증가시켜주었습니다.


예를 들어, M=10, N=12, x=3, y=9 의 입력 값이었다면, x는 3의 값을 고정으로 가지도록 계속 10년씩만 더해줍니다. 
그렇게 되면, x 값은 3에서 변동이 없고, y에 해당하는 값만 10년씩 증가될때마다 값의 변동을 업데이트해주면 됩니다.
그러다가 입력했던 x, y 값과 동일하다면 그때의 연도가 정답이 됩니다.

*/

/*
아래 소스코드는 m과 n 중 더 큰 값을 고정시키도록 수정한 방법입니다.

0ms 나오는 분들도 많지만, 저는 80ms -> 56ms로 조금이라도 줄여진 듯 합니다..

#include <cstdio>
int t, m, n, x, y, a, b, c, d, e, max, ans;
int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int lcm(int a, int b) {
	return a * b / gcd(a, b);
}
int main() {
	scanf("%d", &t);
	while (t-- && scanf("%d %d %d %d", &m, &n, &x, &y)) {
		m > n ? (a = m, b = n, c = x, d = y, e = (x - 1) % n + 1) : (a = n, b = m, c = y, d = x, e = (y - 1) % m + 1);
		for (max = lcm(a, b), ans = -1; c < max; c += a, e = (e + a - 1) % b + 1)
			if (e == d) { ans = c; break; }
		printf("%d\n", ans);
	}
}
*/