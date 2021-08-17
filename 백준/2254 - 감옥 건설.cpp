#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

int n;
ll x, y, bx, by, px, py;
bool chk[1000] = { false };

// 시계 음수, 반시계 양수, 일직선 0
int ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	ll cw = (x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1);
	if (cw > 0) return 1;
	if (cw < 0) return -1;
	return 0;
}

// x좌표 오름차순, y좌표 오름차순 정렬
// 가장 상단 왼쪽이 기준점
bool compAscXAscY(pair<int, pair<ll, ll>>& a, pair<int, pair<ll, ll>>& b) {
	if (a.second.first == b.second.first) return a.second.second < b.second.second;
	else return a.second.first < b.second.first;
}

// 기준점에서 시계 반대 방향으로 정렬
bool comp(pair<int, pair<ll, ll>>& a, pair<int, pair<ll, ll>>& b) {
	int res = ccw(bx, by, a.second.first, a.second.second, b.second.first, b.second.second);
	if (res == 0) { // 일직선인 경우 상단 좌측 순
		if (a.second.first == b.second.first) return a.second.second < b.second.second;
		else return a.second.first < b.second.first;
	}
	else {
		return res > 0;
	}
}

bool isInside(vector<pair<int, pair<ll, ll>>>& outer, ll ix, ll iy) {
	if (outer.size() <= 2) return false; // 정점이 2개 이하면 포함시킬 수 없음
	int cwBase = ccw(outer[0].second.first, outer[0].second.second, outer[1].second.first, outer[1].second.second, ix, iy);
	int sz = outer.size();
	for (int i = 1; i < sz; i++) {
		int cw = ccw(outer[i].second.first, outer[i].second.second, outer[(i + 1) % sz].second.first, outer[(i + 1) % sz].second.second, ix, iy);
		if (cw != cwBase) return false;
	}
	return true;
}


void createConvexHull(vector<pair<int, pair<ll, ll>>>& pos, vector<pair<int, pair<ll, ll>>>& hull) {
	if (pos.size() == 0) return;
	sort(pos.begin(), pos.end(), compAscXAscY);
	bx = pos[0].second.first, by = pos[0].second.second; // 기준점 조정
	sort(pos.begin() + 1, pos.end(), comp);
	hull.push_back(pos[0]);
	if (pos.size() == 1) return;
	hull.push_back(pos[1]);

	for (int i = 2; i < pos.size(); i++) {
		while (hull.size() >= 2) {
			pair<int, pair<ll, ll>> a = hull.back();
			hull.pop_back();
			pair<int, pair<ll, ll>> b = hull.back();
			ll res = ccw(pos[i].second.first, pos[i].second.second, a.second.first, a.second.second, b.second.first, b.second.second);
			if (res < 0) {
				hull.push_back(a);
				break;
			}
		}
		hull.push_back(pos[i]);
	}
}

int main() {
	vector<pair<int, pair<ll, ll>>> pos1, pos2;
	vector<pair<int, pair<ll, ll>>> hull;
	scanf("%d %lld %lld", &n, &px, &py);
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &x, &y);
		pos1.push_back({ i, { x, y } });
	}

	int cnt = 0;
	while (1) {
		vector<pair<int, pair<ll, ll>>>& cur = cnt % 2 ? pos2 : pos1;
		vector<pair<int, pair<ll, ll>>>& nxt = cnt % 2 ? pos1 : pos2;
		createConvexHull(cur, hull);
		if (!isInside(hull, px, py)) break;
		while (!hull.empty()) {
			chk[hull.back().first] = true;
			hull.pop_back();
		}
		for (int i = 0; i < cur.size(); i++) {
			if (chk[cur[i].first]) continue;
			nxt.push_back(cur[i]);
		}
		cur.clear();
		cnt++;
	}
	printf("%d", cnt);
}

/*
주어진 담의 위치로 컨벡스헐을 구하면서, 이미 구한 컨벡스헐의 담들은 제외하고 다음 컨벡스헐을 구해줍니다.
컨벡스헐을 구할 때마다 주어진 감옥이 컨벡스헐 내부에 포함되는지 검사해줍니다.
*/