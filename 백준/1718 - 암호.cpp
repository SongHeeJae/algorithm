#include <iostream>
#include <string>
using namespace std;

void vigenereCipher(string& s, string& k) {
	int j = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ') printf(" ");
		else
			printf("%c", s[i] - k[j] <= 0 ? 'z' - k[j] + s[i] : 'a' + s[i] - k[j] - 1);
		if (++j == k.length()) j = 0;
	}
	printf("\n");
}

int main() {
	string s, k;
	getline(cin, s);
	getline(cin, k);
	vigenereCipher(s, k);
}