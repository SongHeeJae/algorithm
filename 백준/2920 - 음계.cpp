#include <iostream>
int main()
{
	int n, m, i=7, k=0;
	for (scanf("%d", &n);i-- && scanf("%d", &m); n=m)
	{
		if (m == n + 1) k++;
		else if (m == n - 1) k--;
		else break;
	}
	if (k == 7) printf("ascending");
	else if (k == -7) printf("descending");
	else printf("mixed");
}