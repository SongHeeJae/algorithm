#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;

int t, n;
long long x, y;
vector<pair<ll, ll>> pos;
vector<pair<ll, ll>> hull;

// 시계 음수, 반시계 양수, 일직선 0
ll ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	return (x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1);
}

bool compDescYAscX(pair<ll, ll>& a, pair<ll, ll>& b) {
	if (a.second == b.second) return a.first < b.first;
	else return a.second > b.second;
}

bool comp(pair<ll, ll>& a, pair<ll, ll>& b) {
	ll res = ccw(pos[0].first, pos[0].second, a.first, a.second, b.first, b.second);
	if (res == 0) {
		if (a.second == b.second) return a.first < b.first;
		else return a.second > b.second;
	}
	else {
		// 기준점, a, b가 시계 방향을 이루도록 정렬
		return res < 0;
	}
}

int main() {
	scanf("%d", &t);
	while (t--) {
		pos.clear();
		hull.clear();

		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%lld %lld", &x, &y);
			pos.push_back({ x, y });
		}

		sort(pos.begin(), pos.end(), compDescYAscX);
		sort(pos.begin() + 1, pos.end(), comp);

		hull.push_back(pos[0]);
		hull.push_back(pos[1]);
		
		for (int i = 2; i< pos.size(); i++) {
			while (hull.size() >= 2) {
				pair<ll, ll> a = hull.back();
				hull.pop_back();
				pair<ll, ll> b = hull.back();
				ll res = ccw(pos[i].first, pos[i].second, a.first, a.second, b.first, b.second);
				if (res > 0) {
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
}

/*
y 내림차순, x 오름차순으로 정렬하여 기준점을 구하고,
나머지 좌표들을 기준점에서 시계 방향으로 정렬하여 볼록껍질을 만들어주었습니다. 
*/