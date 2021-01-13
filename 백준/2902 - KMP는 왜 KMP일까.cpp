#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
	char word[101];
	scanf("%s", word, sizeof(word));
	printf("%c", word[0]);
	for (int i = 1; i < strlen(word); i++)
		if (word[i - 1] == '-') printf("%c", word[i]);
}