#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int a[500000];
int b[500000];
int n;
long long int c = 0;

void merge(int l, int r) {
	if (l >= r) return;

	int mid = (l + r) / 2;
	int i = l, j = mid + 1, k = l;

	merge(l, mid);
	merge(mid + 1, r);
	
	while (i <= mid && j <= r) {
		if (a[i] > a[j]) {
			b[k++] = a[j++];
			c += mid + 1 - i; // 왼쪽 남은 배열 개수
		}
		else b[k++] = a[i++];
	}

	while (i <= mid) b[k++] = a[i++];
	while (j <= r) b[k++] = a[j++];

	for (int i = l; i <= r; i++) a[i] = b[i];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) cin >> a[i];
	merge(0, n-1);

	cout << c;
}
