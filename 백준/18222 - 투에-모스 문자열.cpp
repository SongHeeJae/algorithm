#include <cstdio>
int main() {
	long long k;
	int ans = 0;
	scanf("%lld", &k);
	k--;
	while (k) {
		ans += k % 2;
		k /= 2;
	}
	printf("%d", ans % 2);
}

/*
k - 1번 째부터 절반씩 줄여나가며, 2의 배수일 때만 문자를 뒤바꿔주었습니다.
*/