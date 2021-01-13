#include <iostream>
#include <string>
using namespace std;
int n, m;
string s;
int isPalindrome() {
	for (int i = 0; i < s.length() / 2; i++)
		if (s[i] != s[s.length() - 1 - i]) return 0;
	return 1;
}
int canPalindrome() {
	for (int k = 0; k < 2; k++) {
		int f = 0;
		for (int i = 0, j = s.length() - 1; i <= j + 2; i++, j--) {
			if (s[i] != s[j]) {
				if (f) {
					f = 0;
					break;
				}
				k ? j-- : i++;
				f = 1;
			}
		}
		if (f) return 1;
	}
	return 0;
}
int check() {
	if (isPalindrome()) return 0;
	else if (canPalindrome()) return 1;
	else return 2;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		cout << check() << "\n";
	}
}