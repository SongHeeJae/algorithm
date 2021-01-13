#include <iostream>
#include <string>
int main()
{
	int n, l;
	std::string c[3072] = { "*", "* *", "*****"};
	scanf("%d", &n);
	for (int i = 3; i < n; i *= 2)
	{
		l = i * 2 - 1;
		for (int j = i; j < i * 2; j++, l -= 2)
		{
			c[j] = c[j - i];
			for (int k = 0; k < l; k++) c[j] += ' ';
			c[j] += c[j - i];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1 - i; j++, c[i] += " ") printf(" ");
		printf("%s\n", c[i].c_str());
	}
}