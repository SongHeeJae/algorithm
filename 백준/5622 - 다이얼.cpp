#include <iostream>
#include <cstring>

int main() {
	const char* time = {"33344455566677788889990000"};
	char words[16];
	scanf("%s", words, sizeof(words));
	int s = 0;
	for (int i = 0; i < strlen(words); i++)
		s += time[words[i] - 65] - 48 != 0 ? time[words[i] - 65] - 48 : 10;
	printf("%d\n", s);
}