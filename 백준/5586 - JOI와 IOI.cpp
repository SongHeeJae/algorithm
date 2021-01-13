#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	int c1 = 0, c2 = 0;
	cin >> s;
	for (int i = 2; i < s.length(); i++) {
		if (s[i] == 'I' && s[i-1] == 'O') {
			if (s[i - 2] == 'J') c1++;
			else if (s[i - 2] == 'I') c2++;
		}
	}
	cout << c1 << "\n" << c2 << "\n";
}

