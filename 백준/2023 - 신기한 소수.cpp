#include <iostream>
#include <cmath>
using namespace std;

int n;

bool isPrime(int num) {
	if (num < 2) return false;
	int mx = sqrt(num);
	for (int i = 2; i <= mx; i++) {
		if (num % i == 0) return false;
	}
	return true;
}

void dfs(int num, int depth) {
	if (depth == n) {
		cout << num << "\n";
		return;
	}

	for (int i = 1; i < 10; i++) {
		int next = num * 10 + i;
		if (isPrime(next))
			dfs(next, depth + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	dfs(0, 0);
}

/*
한 자리수의 뒤에 N 자리수까지 숫자를 덧붙여나가며, 덧붙여진 수가 소수인지 검사해주었습니다.
*/