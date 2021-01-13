#include <iostream>
#include <algorithm>
using namespace std;
int k, v[10] = { 0 };
long long int m1 = -1, m2 = 1e10;
char sign[11];
void f(int c, int p, long long int val) {
	if (c == k + 1) {
		m1 = max(m1, val);
		m2 = min(m2, val);
		return;
	}
	for (int i = 0; i < 10; i++) {
		if (v[i] || sign[c - 1] == '<' && p > i || sign[c - 1] == '>' && p < i) continue;
		v[i] = 1;
		f(c + 1, i, val * 10 + i);
		v[i] = 0;
	}
}
void print(long long int m) {
	for (int i = k; i >= 0; m /= 10, i--) sign[i] = m % 10 + '0';
	printf("%s\n", sign);
}
int main() {
	scanf("%d", &k);
	for (int i = 0; i < k; i++) scanf(" %c", &sign[i]);
	for (int i = 0; i < 10; i++) {
		v[i] = true;
		f(1, i, i);
		v[i] = false;
	}
	sign[k + 1] = '\0';
	print(m1);
	print(m2);
}

/*
부등호 조건에 맞게 수를 나열해서 최대, 최솟값을 구해주었습니다.
범위를 제대로 신경쓰지않아서 오답이 나왔었는데, 정답 수는 최대 9876543210까지 나올 수 있으므로 long long int로 값을 계산해주었습니다. 
*/