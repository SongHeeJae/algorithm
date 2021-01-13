#include <iostream>
int main()
{
	int n = 0;
	bool t=false;
	char c;
	while (scanf("%c", &c))
	{
		if (c == '\n') break;
		else if (c == ' ') t = false;
		else
		{
			if (!t) n++;
			t = true;
		}

	}
	printf("%d", n);
}