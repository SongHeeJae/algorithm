#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, c = 1, f = 0;
	string s;
	cin >> n;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'S') c++;
		else {
			if (f) {
				c++;
				f = 0;
			}
			else f = 1;
		}
	}
	cout << (n>c ? c : n);
}
