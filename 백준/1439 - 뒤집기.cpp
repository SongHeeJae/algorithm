#include <iostream>
#include <algorithm>
using namespace std;

string s;
int zc = 0, oc = 0;
int main() {
	cin >> s;
	char v = s[0];
	zc = v == '0';
	oc = v == '1';
	for (int i = 1; i < s.size(); i++) {
		if (v != s[i]) {
			v = s[i];
			zc += v == '0';
			oc += v == '1';
		}
	}
	cout << min(zc, oc);
}

/*
연속된 1의 구간과 연속된 0의 구간 중 더 적은 구간의 수를 뒤집으면,
최소 횟수로 모두 같은 숫자를 만들 수 있습니다.
*/