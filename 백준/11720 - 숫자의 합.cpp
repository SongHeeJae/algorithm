#include <iostream>
using namespace std;
int main()
{
	int a, b, sum=0;
	cin >> a;
	getchar();
	while (a--) sum += getchar()-'0';
	printf("%d", sum);
}