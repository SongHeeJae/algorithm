#include <iostream>
using namespace std;
int main()
{
	int a, b, c=0;
	cin >> a;
	while (a)
	{
		b = c++;
		while (b--) printf(" ");
		b = a--;
		while (b--) printf("*");
		printf("\n");
	}
}