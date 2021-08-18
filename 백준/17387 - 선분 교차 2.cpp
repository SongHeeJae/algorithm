#include <iostream>
using namespace std;

typedef long long ll;

// 시계 음수, 반시계 양수, 일직선 0
int ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	ll cw = (x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1);
	if (cw > 0) return 1;
	if (cw < 0) return -1;
	return 0;
}

// a-b, c-d가 교차하는지 확인
// ccw(a,b,c) * ccw(a,b,d) == 0 && ccw(b,d,a) * ccw(b,d,c) == 0이면
// a--c--b--d 형태일 때 교차했다고 봄
// 그렇지 않으면,
// ccw(a,b,c) * ccw(a,b,d) <= 0 && ccw(b,d,a) * ccw(b,d,c) <= 0이면 교차
bool isCross(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c, pair<ll, ll> d) {
	int ab = ccw(a.first, a.second, b.first, b.second, c.first, c.second)
		* ccw(a.first, a.second, b.first, b.second, d.first, d.second);
	int cd = ccw(c.first, c.second, d.first, d.second, a.first, a.second)
		* ccw(c.first, c.second, d.first, d.second, b.first, b.second);
	if (ab == 0 && cd == 0) {
		// 겹치는 부분이 있는지 확인
		// first 비교 후, second 비교
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);
		return c <= b && a <= d;
	}
	else {
		return ab <= 0 && cd <= 0;
	}
}

int main() {
	pair<ll, ll> a, b, c, d;
	scanf("%lld %lld %lld %lld", &a.first, &a.second, &b.first, &b.second);
	scanf("%lld %lld %lld %lld", &c.first, &c.second, &d.first, &d.second);
	printf("%d", isCross(a, b, c, d));
}

/*
두 선분이 교차하는지 판별하는 방법은 아래 링크에 나와있습니다.
https://blog.naver.com/gmlwo308/222462695063
*/