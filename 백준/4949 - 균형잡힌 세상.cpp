#include <iostream>
#include <string>
using namespace std;

bool isBalance(string& s) {
	char stk[101];
	int index = 0;
	for (int i = 0; i < s.length() - 1; i++) {
		if (s[i] == '(' || s[i] == '[') stk[index++] = s[i];
		else if (s[i] == ')') {
			if (index > 0 && stk[index - 1] == '(') index--;
			else return false;
		}
		else if (s[i] == ']') {
			if (index > 0 && stk[index - 1] == '[') index--;
			else return false;
		}
	}
	return index == 0 ? true : false;
}

int main() {
	
	while (1) {
		string s;
		getline(cin, s);
		if (s == ".") break;
		if (isBalance(s)) printf("yes\n");
		else printf("no\n");
	}
	
}

