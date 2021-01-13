#include <iostream>
#include <algorithm>

long long search(int* b, int l, int r, int data)
{
	int mid;
	long long count = 0;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (b[mid] == data)
		{
			count++;
			for (int i = mid + 1; i <= r && b[i] == data; i++, count++);
			for (int i = mid - 1; i >= l && b[i] == data; i--, count++);
			return count;

		}
		else if (b[mid] > data) r = mid - 1;
		else l = mid + 1;
	}
	return count;
}

int main()
{
	int* a[4];
	int* b, * c;
	int n, k = 0;
	long long count = 0, temp;
	scanf("%d", &n);
	for (int i = 0; i < 4; i++) a[i] = new int[n];
	b = new int[n * n];
	c = new int[n * n];
	for (int i = 0; i < n; i++)
		scanf("%d %d %d %d", &a[0][i], &a[1][i], &a[2][i], &a[3][i]);


	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			b[k] = a[0][i] + a[1][j];
			c[k++] = a[2][i] + a[3][j];
		}

	std::sort(b, b + k);
	std::sort(c, c + k);

	for (int i = 0; i < k; i++)
	{
		if (i > 0 && c[i] == c[i - 1]) count += temp;
		else count += (temp=search(b, 0, k - 1, -c[i]));
	}

	printf("%lld", count);
    
    delete[] a[0];
    delete[] a[1];
    delete[] a[2];
    delete[] a[3];
    delete[] b;
    delete[] c;
}

/*
#include <iostream>
#include <algorithm>

int main()
{
	int* a[4];
	int* b, * c;
	int n, k = 0;
	long long count = 0;
	scanf("%d", &n);
	for (int i = 0; i < 4; i++) a[i] = new int[n];
	b = new int[n * n];
	c = new int[n * n];
	for (int i = 0; i < n; i++)
		scanf("%d %d %d %d", &a[0][i], &a[1][i], &a[2][i], &a[3][i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			b[k] = a[0][i] + a[1][j];
			c[k++] = a[2][i] + a[3][j];
		}

	std::sort(b, b + k);
	std::sort(c, c + k);

	for (int i = 0; i < k; i++)
		count += std::upper_bound(b, b + k, -c[i]) - std::lower_bound(b, b + k, -c[i]);

	printf("%lld", count);
}
*/

/*
#include <iostream>
#include <algorithm>

long long search(int* b, int l, int r, int data)
{
	int mid;
	long long count = 0;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (b[mid] == data)
		{
			count++;
			for (int i = mid + 1; i <= r && b[i] == data; i++, count++);
			for (int i = mid - 1; i >= l && b[i] == data; i--, count++);
			return count;

		}
		else if (b[mid] > data) r = mid - 1;
		else l = mid + 1;
	}
	return count;
}

int main()
{
	int* a[4];
	int* b, * c;
	int n, k = 0;
	long long count = 0, temp;
	scanf("%d", &n);
	for (int i = 0; i < 4; i++) a[i] = new int[n];
	b = new int[n * n];
	c = new int[n * n];
	for (int i = 0; i < n; i++)
		scanf("%d %d %d %d", &a[0][i], &a[1][i], &a[2][i], &a[3][i]);


	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			b[k] = a[0][i] + a[1][j];
			c[k++] = a[2][i] + a[3][j];
		}

	std::sort(b, b + k);
	std::sort(c, c + k);

	for (int i = 0; i < k; i++)
	{
		if (i > 0 && c[i] == c[i - 1]) count += temp;
		else count += (temp=search(b, 0, k - 1, -c[i]));
	}

	printf("%lld", count);
}
*/