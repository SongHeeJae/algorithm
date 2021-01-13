#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int palindrome(char *word) {
	for (int i = 0; i < strlen(word) / 2; i++) {
		if (word[i] != word[strlen(word) - i - 1]) {
			return 0;
		}
	}
	return 1;
}

int main() {
	char word[101];
	scanf("%s", word, sizeof(word));
	printf("%d\n", palindrome(word));
}