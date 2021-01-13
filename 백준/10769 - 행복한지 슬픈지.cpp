#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	int c1 = 0, c2 = 0;
	for (int i = 0; i < s.length(); i++) {
		if (i + 2 < s.length() && s[i] == ':' && s[i + 1] == '-' && s[i + 2] == ')') c1++;
		else if (i + 2 < s.length() && s[i] == ':' && s[i + 1] == '-' && s[i + 2] == '(') c2++;
	}
	if (!(c1+c2)) cout << "none\n";
	else if (c1 > c2) cout << "happy\n";
	else if (c1 < c2) cout << "sad\n";
	else cout << "unsure\n";
}