#include <iostream>
using namespace std;
int main()
{
	int a, b, c=1;
	cin >> a;
	while (a--)
	{
		b = c++;
		while (b--) printf("*");
		printf("\n");
	}
}