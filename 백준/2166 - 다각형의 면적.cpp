#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;

int n;
int p[10000][2];

ll ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	return (x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &p[i][0], &p[i][1]);
	}

	ll ans = 0;
	for (int i = 2; i < n; i++) {
		ans += ccw(
			p[0][0], p[0][1],
			p[i - 1][0], p[i - 1][1],
			p[i][0], p[i][1]
		);
	}
	printf("%.1lf", abs(ans / 2.0));
}

/*
벡터의 외적을 이용해서 다각형의 면적을 구해주었습니다.
*/