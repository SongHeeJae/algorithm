#include <cstdio>
int main()
{
	int n, alp[26] = {0,}, f = 1;
	char word[31];
	scanf("%d", &n);
	while (n-- && scanf("%s", word)) alp[word[0] - 'a']++;
	for (int i = 0; i < 26; i++)
		if (alp[i] > 4) {
			printf("%c", i + 'a');
			f = 0;
		}
	if (f) printf("PREDAJA");
}