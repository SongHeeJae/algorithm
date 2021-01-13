#include <iostream>
#include <string>
using namespace std;

int stringToInt(string n) {
	int res = 0;
	for (int i = 0; i<n.length(); i++) {
		res += n[i] - '0';
		res *= 10;
	}
	return res / 10;
}

int main() {
	string s1, s2, s15, s16, s25, s26;
	cin >> s1 >> s2;
	s15 = s16 = s1;
	s25 = s26 = s2;
	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] == '6' || s1[i] == '5') {
			s15[i] = '5';
			s16[i] = '6';
		}
	}
	for (int i = 0; i < s2.length(); i++) {
		if (s2[i] == '6' || s2[i] == '5') {
			s25[i] = '5';
			s26[i] = '6';
		}
	}
	cout << stringToInt(s15) + stringToInt(s25) << " ";
	cout << stringToInt(s16) + stringToInt(s26) << "\n";
}

