#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int t;
ll lx, ty, rx, by;
pll s, e, lt, lb, rt, rb;

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
bool isCross(pll a, pll b, pll c, pll d) {
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

bool isInside(pll& x) {
	return lt.first < x.first && x.first < lb.first
		&& lt.second < x.second && x.second < rt.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> s.first >> s.second >> e.first >> e.second 
			>> lx >> ty >> rx >> by;
		
		lt = { min(lx, rx), min(ty, by) };
		lb = { max(lx, rx), min(ty, by) };
		rt = { min(lx, rx), max(ty, by) };
		rb = { max(lx, rx), max(ty, by) };

		if ((isInside(s) && isInside(e))
			|| isCross(s, e, lt, lb)
			|| isCross(s, e, lt, rt)
			|| isCross(s, e, rb, lb)
			|| isCross(s, e, rb, rt))
			cout << "T\n";
		else cout << "F\n";
	}
}

/*
주어진 직사각형의 좌표는 대각선 위치에 있는 임의의 두 좌표가 주어집니다.
이를 통해 직사각형의 네 좌표를 구하고,
네 개의 변과 선분의 교차 여부, 직사각형 내에 선분 포함 여부 를 판별하였습니다. 
선분이 교차하는지 판별하는 방법은 아래 링크의 두 번째 그림에 나와있습니다.
https://blog.naver.com/gmlwo308/222462695063
*/