#include <iostream>
#include <string>
using namespace std;

int main() {
	int fbi[5] = { 0, }, num = 0;
	for (int i = 1; i <= 5; i++) {
		string s;
		cin >> s;
		for (int j = 2; j < s.length(); j++) {
			if (s[j] == 'I' && s[j - 1] == 'B' && s[j - 2] == 'F') {
				fbi[num++] = i;
				break;
			}
		}
	}
	if (num == 0) printf("HE GOT AWAY!\n");
	else {
		for (int i = 0; i < num; i++) printf("%d ", fbi[i]);
	}
}

