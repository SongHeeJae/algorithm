#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int arr[100000], n, ans = -1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + n);
	for (int i = 0; i < n; i++)
		ans = max(ans, arr[i] * (n - i));
	printf("%d", ans);
}