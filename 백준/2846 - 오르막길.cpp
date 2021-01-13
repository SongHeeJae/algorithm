#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n, a = 0, ans = -1, arr[1000];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	for (int i = 1; i < n; i++) {
		if (arr[i] > arr[i - 1]) a += arr[i] - arr[i - 1];
		else {
			ans = max(a, ans);
			a = 0;
		}
	}
	printf("%d\n", max(a, ans));
}