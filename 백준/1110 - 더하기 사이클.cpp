#include <iostream>
using namespace std;

int main()
{
	int n, m, c=0;
	scanf("%d", &m);
	for (n=m;c==0 || m!=n;c++) n = (n % 10 + n / 10) % 10 + n % 10 * 10;
	printf("%d", c);
}