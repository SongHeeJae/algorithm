#include <iostream>
using namespace std;

string str, str1, str2;
int cnt = 0;

bool isPalindrome(string& s) {
	for (int i = 0; i < s.length() / 2; i++)
		if (s[i] != s[s.length() - 1 - i]) return false;
	return true;
}

int main() {
	cin >> str;
	str1 = str2 = str;
	while (!isPalindrome(str1) && !isPalindrome(str2)) {
		str1 = str1 + str[str.length() - 2 - cnt];
		str2 = str + str[cnt] + str2.substr(str2.length() - cnt);
		cnt++;
	}
	cout << str.length() + cnt;
}

/*
abc가 있으면,
abcb
abcba
또는,
abca
abcba
위와 같은 방법으로 문자를 덧붙여나가며 팰린드롬인지 확인해주었습니다.
*/