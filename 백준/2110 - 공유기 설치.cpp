#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& house, int l, int r, vector<int>& buf) {

	if (l >= r) return;

	int mid = (r + l) / 2;
	int i = l, j = mid + 1, k = l;

	merge(house, l, mid, buf);
	merge(house, mid + 1, r, buf);

	while (i <= mid && j <= r) {
		if (house[i] > house[j]) buf[k++] = house[j++];
		else buf[k++] = house[i++];
	}

	while (i <= mid) buf[k++] = house[i++];
	while (j <= r) buf[k++] = house[j++];

	for (int i = l; i <= r; i++) house[i] = buf[i];
}

int main() {
	int n, c, max;
	scanf("%d %d", &n, &c);
	vector<int> house(n), buf(n);
	for (int i = 0; i < n; i++) scanf("%d", &house[i]);
	merge(house, 0, n - 1, buf);

	int l = 1, r = house[n - 1] - house[0], ans = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		int p = house[0], count = 1;
		for (int i = 1; i < n; i++) {
			if (house[i] - p >= mid) {
				count++;
				p = house[i];
			}
		}
		if (count >= c) {
			l = mid + 1;
			ans = mid > ans ? mid : ans;
		}
		else r = mid - 1;
	}

	printf("%d\n", ans);
}