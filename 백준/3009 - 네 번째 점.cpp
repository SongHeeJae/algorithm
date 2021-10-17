#include <iostream>
using namespace std;

int a, b, x, y;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 3; i++) {
		cin >> a >> b;
		x ^= a;
		y ^= b;
	}
	cout << x << " " << y;
}

/*
XOR 연산으로 한 번만 나온 수를 찾아주었습니다.
*/