#include <iostream>
#include <algorithm>
#define MAX 101
using namespace std;

typedef long long ll;

int n, m, map[MAX][MAX] = { 0 };
ll ans = 0;

int getSum(int tlx, int tly, int brx, int bry) {
	return map[brx][bry] - map[brx][tly - 1] - map[tlx - 1][bry] + map[tlx - 1][tly - 1];
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &map[i][j]);
			map[i][j] += map[i - 1][j] + map[i][j - 1] - map[i - 1][j - 1];
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n - i; j++) {
			ll first = getSum(1, 1, i, m);
			ll second = getSum(i + 1, 1, i + j, m);
			ll third = getSum(i + j + 1, 1, n, m);
			ans = max(ans, first * second * third);
		}
	}

	for (int i = 1; i < m; i++) {
		for (int j = 1; j < m - i; j++) {
			ll first = getSum(1, 1, n, i);
			ll second = getSum(1, i + 1, n, i + j);
			ll third = getSum(1, i + j + 1, n, m);
			ans = max(ans, first * second * third);
		}
	}

	for (int i = 1; i < n; i++) {
		ll first1 = getSum(1, 1, i, m);
		ll first2 = getSum(n - i + 1, 1, n, m);
		for (int j = 1; j < m; j++) {
			ll second1 = getSum(i + 1, 1, n, j);
			ll third1 = getSum(i + 1, j + 1, n, m);
			ll second2 = getSum(1, 1, n - i, j);
			ll third2 = getSum(1, j + 1, n - i, m);
			ans = max(ans, first1 * second1 * third1);
			ans = max(ans, first2 * second2 * third2);
		}
	}

	for (int i = 1; i < m; i++) {
		ll first1 = getSum(1, 1, n, i);
		ll first2 = getSum(1, m - i + 1, n, m);
		for (int j = 1; j < n; j++) {
			ll second1 = getSum(1, i + 1, j, m);
			ll third1 = getSum(j + 1, i + 1, n, m);
			ll second2 = getSum(1, 1, j, m - i);
			ll third2 = getSum(j + 1, 1, n, m - i);
			ans = max(ans, first1 * second1 * third1);
			ans = max(ans, first2 * second2 * third2);
		}
	}
	printf("%lld", ans);
}

/*
map[i][j] = (1, 1) ~ (n, m)의 모양을 가지는 직사각형의 합을 구해줍니다.
이를 이용하여 좌상(x1, y1) 우하(x2, y2) 직사각형의 넓이를 바로 구할 수 있습니다.
직사각형을 나눌 수 있는 6가지 경우를 모두 검사하여 답을 구해주었습니다.
 * 6가지 경우 : 가로 3등분, 세로 3등분, ㅗ, ㅓ, ㅏ, ㅜ
*/