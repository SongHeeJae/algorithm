#include <iostream>
#include <vector>
using namespace std;

int main() {
	int k, n, max = -1;
	scanf("%d %d", &k, &n);
	vector<long long int> lan(k);
	for (int i = 0; i < k && scanf("%lld", &lan[i]); i++) max = lan[i] > max ? lan[i] : max;

	long long int s = 1, e = max;
	while (s <= e) {
		long long int c = 0, mid = (s + e) / 2;
		for (long long int l : lan) c += l/mid;
		if (c >= n) s = mid + 1;
		else e = mid - 1;
	}
	printf("%lld\n", e);
}