#include <iostream>
#include <algorithm>
int n, arr[10000], m, l = 0, r;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n && scanf("%d", &arr[i]); i++)
		r = std::max(r, arr[i]);
	scanf("%d", &m);
	while (l <= r) {
		int mid = (l + r) / 2, sum = 0;
		for (int i = 0; i < n; i++) {
			if (mid >= arr[i]) sum += arr[i];
			else sum += mid;
		}
		if (sum <= m) l = mid + 1;
		else r = mid - 1;
	}
	printf("%d", r);
}