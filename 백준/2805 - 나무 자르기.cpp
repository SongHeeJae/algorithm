#include <iostream>
#include <vector>
using namespace std;

int main() {
	long long int n, m, max = -1;
	scanf("%lld %lld", &n, &m);
	vector<long long int> h(n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &h[i]);
		max = h[i] > max ? h[i] : max;
	}
	long long int l = 1, r = max, s, mid, ans = 0;
	while (l <= r) {
		s = 0;
		mid = (l + r) / 2;
		for (long long int hh : h) s += hh - mid > 0 ? hh - mid : 0;
		if (s >= m) {
			l = mid + 1;
			ans = mid > ans ? mid : ans;
		}
		else r = mid - 1;
	}
	printf("%lld\n", ans);

}