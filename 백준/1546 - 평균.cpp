#include <iostream>
using namespace std;

int main()
{
	int a, n, max = 0, sum = 0;;
	scanf("%d", &n);
	for (int i=0;i<n; sum += a, i++)
	{
		scanf("%d", &a);
		if (a > max) max = a;
	}
	printf("%lf", (double)sum / n / max * 100);
}