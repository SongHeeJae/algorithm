#include <iostream>
using namespace std;
int main()
{
	int n, m, l[1000], x=0;
	double a=0;
	scanf("%d", &n);
	for (;n--; x = 0, a = 0)
	{
		scanf("%d", &m);
		for (int i=0; i < m && scanf("%d", &l[i]); i++) a += l[i];
		a /= m;
		for (int i = 0; i < m; i++) if (l[i] > a) x++;
		printf("%.3lf%%\n", (double)x/m*100);
	}
}