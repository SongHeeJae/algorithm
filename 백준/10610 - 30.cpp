#include <iostream>
#include <algorithm>
using namespace std;

string s;
bool hasZero = false;
int sum = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;
	for (auto ss : s) {
		hasZero |= ss == '0';
		sum += ss - '0';
	}
	if (hasZero && sum % 3 == 0) {
		sort(s.begin(), s.end(), greater<>());
		cout << s;
	}
	else cout << -1;
}

/*
0이 하나 있고, 모든 자릿수 합이 3의 배수라면, 30의 배수가 될 수 있었습니다.
*/