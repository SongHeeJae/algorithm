#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;

int n;
ll x, y;
char c;
vector<pair<ll, ll>> pos, hull, res;

// 시계 음수, 반시계 양수, 일직선 0
ll ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	return (x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1);
}

bool compAscXAscY(pair<ll, ll>& a, pair<ll, ll>& b) {
	if (a.first == b.first) return a.second < b.second;
	else return a.first < b.first;
}

bool comp(pair<ll, ll>& a, pair<ll, ll>& b) {
	ll res = ccw(pos[0].first, pos[0].second, a.first, a.second, b.first, b.second);
	if (res == 0) {
		if (a.first == b.first) return a.second > b.second;
		else {
			if (a.second == b.second) return a.first < b.first;
			else return a.second > b.second; // 우상단 대각선일 때, 우상단에 있는 좌표를 먼저 오게 함
		}
	}
	else {
		// 기준점, a, b가 반시계 방향을 이루도록 정렬
		return res > 0;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld %c", &x, &y, &c);
		if (c == 'Y') pos.push_back({ x, y });
	}

	sort(pos.begin(), pos.end(), compAscXAscY);
	sort(pos.begin() + 1, pos.end(), comp);

	hull.push_back(pos[0]);
	hull.push_back(pos[1]);

	for (int i = 2; i < pos.size(); i++) {
		while (hull.size() >= 2) {
			pair<ll, ll> a = hull.back();
			hull.pop_back();
			pair<ll, ll> b = hull.back();
			ll res = ccw(pos[i].first, pos[i].second, a.first, a.second, b.first, b.second);
			if (res <= 0) {
				hull.push_back(a);
				break;
			}
		}
		hull.push_back(pos[i]);
	}

	printf("%d\n", hull.size());
	for (int i = 0; i < hull.size(); i++) {
		printf("%lld %lld\n", hull[i].first, hull[i].second);
	}
}

/*
몇 가지 주의할 점이 있었는데, 이미 볼록 껍질을 찾아낸 좌표가 주어지므로 'Y'로 표시된 좌표는 모두 볼록 껍질에 들어가야만 했습니다. 그래서 변 내에 좌표가 포함된 상황에도 그것을 포함시켜주어야 했습니다.
발견하지 못하던 예외 케이스가 있었는데, 기준점에서 시계 반대 방향으로 정렬할 때, ccw가 0이라면(우상단 대각선) y가 더 큰 좌표가 먼저 선택되어야 볼록 껍질에 포함시킬 수 있었습니다.
*/