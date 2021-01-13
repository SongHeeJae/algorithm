#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string s, x;
	int index = 0;
	vector<char> result(1000000);
	cin >> s >> x;

	for (int i = 0; i < s.length(); i++) {
		result[index++] = s[i];
		if (s[i] == x[x.length() - 1]) {
			bool chk = true;
			for (int j = 0; j < x.length(); j++) {
				if (x[x.length() - 1 - j] != result[index - 1 - j]) {
					chk = false;
					break;
				}
			}
			if (chk) index -= x.length();
		}
	}

	if (index <= 0) printf("FRULA\n");
	else {
		result[index] = '\0';
		printf("%s\n", &result[0]);
	}

	
}

