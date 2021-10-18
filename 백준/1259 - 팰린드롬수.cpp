#include <iostream>
using namespace std;

string s;

bool isPalindrome(string& s) {
	for (int i = 0; i < s.size() / 2; i++) {
		if (s[i] != s[s.size() - 1 - i]) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (1) {
		cin >> s;
		if (s.size() == 1 && s[0] == '0') break;
		cout << (isPalindrome(s) ? "yes" : "no") << "\n";
	}
}