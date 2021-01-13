#include <iostream>
int main()
{
	int d[26] = {0}, max = 0, n=0;
	char c;
	while ((c = getchar()) != '\n') c > 96 ? d[c - 97]++ : d[c - 65]++;
	for (int i = 0; i < 26; i++) if (d[i] > d[max]) max = i;
	for (int i = 0; i < 26; i++) if (d[i] == d[max]) n++;
	n>1 ? printf("?") : printf("%c", max + 65);
}