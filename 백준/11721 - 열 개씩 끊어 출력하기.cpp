#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char s[101];
	int i = 0;
	cin >> s;
	while (i < strlen(s))
	{
		printf("%c", s[i]);
		if (i++ != 0 && i % 10 == 0) printf("\n");
	}
}