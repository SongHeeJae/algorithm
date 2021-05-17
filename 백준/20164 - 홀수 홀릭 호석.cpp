#include <iostream>
#include <algorithm>
#include <string>
#define INF 2147483647
using namespace std;

string start;
int m1 = INF, m2 = 0;

int getOddCount(string& s) {
	int cnt = 0;
	for (int i = 0; i < s.size(); i++)
		if (s[i] % 2) cnt++;
	return cnt;
}

void oddHolic(string s, int c) {
	int oddCnt = getOddCount(s);
	if (s.size() == 1) {
		m1 = min(m1, c + oddCnt);
		m2 = max(m2, c + oddCnt);
	}
	else if (s.size() == 2) {
		oddHolic(to_string((s[0] - '0') + (s[1] - '0')), c + oddCnt);
	}
	else {
		for (int i = 1; i < s.size() - 1; i++) {
			for (int j = i + 1; j < s.size(); j++) {
				oddHolic(to_string(stoi(s.substr(0, i)) + stoi(s.substr(i, j - i)) + stoi(s.substr(j))), c + oddCnt);
			}
		}
	}
}

int main() {
	cin >> start;
	oddHolic(start, 0);
	cout << m1 << " " << m2;
}

/*
주어진 수의 길이에 따라 연산을 수행해줍니다.
연산을 수행할 때마다 홀수의 개수를 더해주고, 수가 한 자리가 되었을 때 최종값을 업데이트해주었습니다.
*/