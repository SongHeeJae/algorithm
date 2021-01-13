#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int val, carry = 0;
string a, b, c;
void f(string &s, int &len) {
	for (; len >= 0; len--) {
		val = s[len] - '0' + carry;
		c.push_back(val % 10 + '0');
		carry = val / 10;
	}
}
int main() {
	cin >> a >> b;
	int alen = a.length() - 1, blen = b.length() - 1;
	for (; alen >= 0 && blen >= 0; alen--, blen--) {
		val = a[alen] - '0' + b[blen] - '0' + carry;
		c.push_back(val % 10 + '0');
		carry = val / 10;
	}
	f(a, alen); // a또는 b의 남은 자릿수에 대해 덧셈
	f(b, blen);
	if (carry == 1) c += '1';
	reverse(c.begin(), c.end());
	cout << c;
}