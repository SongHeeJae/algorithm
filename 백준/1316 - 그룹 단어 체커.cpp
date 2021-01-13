#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, c = 0;
	string word;
	scanf("%d", &n);
	while (n--) {
		bool nums['z' + 1] = { false, };
		int i = 0;
		cin >> word;
		for (i = 0; i < word.length(); i++) {
			if (nums[word[i]] && word[i - 1] != word[i]) break;
			nums[word[i]] = true;
		}
		c = i == word.length() ? c + 1 : c;
	}
	printf("%d\n", c);
}