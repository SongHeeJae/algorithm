#include <iostream>
using namespace std;
int main()
{
	int a, b;
	cin >> a;
	while (a)
	{
		b = a--;
		while (b--) printf("*");
		printf("\n");
	}
}