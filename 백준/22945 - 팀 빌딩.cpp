#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100000

int n, ans = 0, a[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int l = 0, r = n - 1;
	while (l < r) {
		ans = max(ans, (r - l - 1) * min(a[l], a[r]));
		if (a[l] < a[r]) l++;
		else r--;
	}
	cout << ans;
}

/*
시작과 끝을 나타내는 두 개의 포인터를 두고, 더 작은 능력치의 개발자 범위를 안쪽으로 좁혀주며 능력치의 최대값을 구해주었습니다.
*/