#include <iostream>
#include <algorithm>

void search(int l, int r, int* n, int d)
{
	int m;
	while (l <= r)
	{
		m = (l + r) / 2;
		if (n[m] == d)
		{
			puts("1"); return;
		}
		else if (n[m] > d) r = m - 1;
		else l = m + 1;
	}
	puts("0");
}

int main()
{
	int a, * n, b, d;
	scanf("%d", &a);
	n = new int[a];
	for (int i = 0; i < a && scanf("%d", &d); i++) n[i] = d;

	std::sort(n, n+a);
	scanf("%d", &b);
	while (b--)
	{
		scanf("%d", &d);
		search(0, a - 1, n, d);
	}

	delete[] n;
}
