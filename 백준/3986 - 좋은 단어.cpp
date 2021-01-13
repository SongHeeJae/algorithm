#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int n, index, c = 0;
	vector<int> s(100000);
	scanf("%d", &n);
	while (n--) {
		string s;
		cin >> s;
		index = 0;
		for (int i = 0; i < s.length(); i++) {
			if (index > 0 && s[index - 1] == s[i]) index--;
			else s[index++] = s[i];
		}
		if (index == 0) c++;
	}
	cout << c << "\n";
}

