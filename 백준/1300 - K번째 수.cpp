#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	int l = 1, r = k, ans = 0;
	while (l <= r) {
		int mid = (l + r) / 2, c = 0;
		for (int i = 1; i <= n; i++) c += min(n, mid / i);
		if (c < k) l = mid + 1;
		else {
			r = mid - 1;
			ans = mid;
		}
	}
	printf("%d\n", ans);
}