#include <iostream>
using namespace std;
int main()
{
	int a, b=1;
	cin >> a;
	while (b<10) printf("%d * %d = %d\n", a, b++, a*b);
}