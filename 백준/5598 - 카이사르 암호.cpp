#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int alp['Z' + 1];
	for (int i = 'C'; i <= 'Z'; i++) alp[i] = i - 3;
	for (int i = 0; i < 3; i++) alp['A' + i] = 'X' + i;
	char word[1001];
	scanf("%s", word, sizeof(word));
	for (int i = 0; i < strlen(word); i++) word[i] = alp[word[i]];
	printf("%s", word);
}

