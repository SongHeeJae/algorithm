#include <iostream>
#include <string>
using namespace std;

int n;
string s, s1, s2;

void f(char ch, int c) {
	
	if (c - 1 == n) {
		cout << s;
		exit(0);
	}
	s += ch;
	for (int i = 1; i <= c / 2; i++) {
		s1 = s.substr(c - i, i);
		s2 = s.substr(c - i * 2, i);
		if (s1 == s2) {
			s = s.substr(0, c - 1);
			return;
		}
	}

	f('1', c+1);
	f('2', c+1);
	f('3', c+1);
	s = s.substr(0, c - 1);
}

int main() {
	scanf("%d", &n);
	f('1', 1);
}