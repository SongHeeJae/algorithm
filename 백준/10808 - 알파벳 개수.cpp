#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
	int alp['z' + 1] = { 0, };
	char word[101];
	scanf("%s", word, sizeof(word));
	for (int i = 0; i < strlen(word); i++) alp[word[i]]++;
	for (int i = 'a'; i <= 'z'; i++) printf("%d ", alp[i]);
}