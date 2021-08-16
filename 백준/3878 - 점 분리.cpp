#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

int t, n, m;
ll x, y, bx, by;
vector<pair<ll, ll>> blackPos, whitePos, blackHull, whiteHull;

// 시계 음수, 반시계 양수, 일직선 0
int ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	ll cw = (x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1);
	if (cw > 0) return 1;
	if (cw < 0) return -1;
	return 0;
}

// x좌표 오름차순, y좌표 오름차순 정렬
// 가장 상단 왼쪽이 기준점
bool compAscXAscY(pair<ll, ll>& a, pair<ll, ll>& b) {
	if (a.first == b.first) return a.second < b.second;
	else return a.first < b.first;
}

// 기준점에서 시계 반대 방향으로 정렬
bool comp(pair<ll, ll>& a, pair<ll, ll>& b) {
	int res = ccw(bx, by, a.first, a.second, b.first, b.second);
	if (res == 0) { // 일직선인 경우 상단 좌측 순
		if (a.first == b.first) return a.second < b.second;
		else return a.first < b.first;
	}
	else {
		return res > 0;
	}
}

void createConvexHull(vector<pair<ll, ll>>& pos, vector<pair<ll, ll>>& hull) {
	sort(pos.begin(), pos.end(), compAscXAscY);
	bx = pos[0].first, by = pos[0].second; // 기준점 조정
	sort(pos.begin() + 1, pos.end(), comp);
	hull.push_back(pos[0]);
	if (pos.size() == 1) return;
	hull.push_back(pos[1]);

	for (int i = 2; i < pos.size(); i++) {
		while (hull.size() >= 2) {
			pair<ll, ll> a = hull.back();
			hull.pop_back();
			pair<ll, ll> b = hull.back();
			ll res = ccw(pos[i].first, pos[i].second, a.first, a.second, b.first, b.second);
			if (res < 0) {
				hull.push_back(a);
				break;
			}
		}
		hull.push_back(pos[i]);
	}
}

void inputPos(vector<pair<ll, ll>>& pos, int size) {
	for (int i = 0; i < size; i++) {
		scanf("%lld %lld", &x, &y);
		pos.push_back({ x, y });
	}
}

// 좌표가 outer 안에 포함되어있는지 확인
// 컨벡스헐의 모든 변과 해당 좌표가 같은 방향을 이루는지 검사
bool isInside(vector<pair<ll, ll>>& outer, pair<ll, ll>& p) {
	if (outer.size() <= 2) return false; // 정점이 2개 이하면 포함시킬 수 없음
	int cwBase = ccw(outer[0].first, outer[0].second, outer[1].first, outer[1].second, p.first, p.second);
	int sz = outer.size();
	for (int i = 1; i < sz; i++) {
		int cw = ccw(outer[i].first, outer[i].second, outer[(i + 1) % sz].first, outer[(i + 1) % sz].second, p.first, p.second);
		if (cw != cwBase) return false;
	}
	return true;
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

// 흰색, 검정색 두 개의 그룹으로 나눌 수 있는지 확인
bool isDivide() {

	// 두 개의 컨벡스헐이 서로 포함 관계에 있는지 검사
	// 그룹 내에 다른 색 점이 하나라도 포함된다면 직선으로 점을 분리할 수 없음 
	if (isInside(blackHull, whiteHull[0]) || isInside(whiteHull, blackHull[0])) return false;

	// 두 컨벡스헐의 모든 엣지가 교차하지 않는지 검사
	int bsz = blackHull.size();
	int wsz = whiteHull.size();
	for (int i = 0; i < bsz; i++) {
		for (int j = 0; j < wsz; j++) {
			if (isCross(blackHull[i], blackHull[(i + 1) % bsz],
				whiteHull[j], whiteHull[(j + 1) % wsz])) {
				return false;
			}
		}
	}
	return true;
}


int main() {
	scanf("%d", &t);
	while (t--) {
		blackPos.clear();
		whitePos.clear();
		blackHull.clear();
		whiteHull.clear();

		scanf("%d %d", &n, &m);

		inputPos(blackPos, n);
		inputPos(whitePos, m);

		createConvexHull(blackPos, blackHull);
		createConvexHull(whitePos, whiteHull);

		if (isDivide()) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
}

/*
풀이 링크 : https://blog.naver.com/gmlwo308/222462695063

흰 점과 검은 점이 분리가 되는지 확인하려면,
각 색 그룹의 점들을 모두 포함하는 두 개의 컨벡스헐을 만들어낸 뒤,
두 컨벡스헐이 서로 포함 관계에 있지 않고, 교차되는 부분이 없다면 분리시킬 수 있습니다.

서로 포함 관계에 있는지는 다음과 같이 알 수 있습니다.

두 개의 컨벡스헐 A, B가 있고, A의 내부에 B를 포함하고 있습니다.
B에서 임의의 점 X를 선택하여 A의 모든 변과 ccw를 구하여 방향성을 확인해보겠습니다.
A의 변을 시계 방향으로 돌려가며 X와 ccw를 구한다면, 모든 변에 대하여 시계 방향으로 나오니 동일한 값이 나오게 됩니다.
만약 외부에 있는 임의의 점 Y를 선택하여 A의 모든 변과 ccw를 구한다면, 동일한 값이 나오지 않고 방향성이 달라지게 됩니다.
특정한 색의 그룹 내에 다른 색 점이 하나라도 포함된다면, 직선으로 점을 분리할 수 없게 됩니다.

위 과정에서 검사했던 점이 Y처럼 포함되어있지 않더라도, 분리시킬 수 있는지 완벽하게 확인하진 못합니다.
Y는 포함되지 않더라도 그 외의 다른 좌표는 A내에 포함될 수도 있고, n과 m이 다각형을 이루지 못할 정도로 그 좌표의 개수가 적어서 포함 관계를 확인하지 못할 수도 있습니다.
그래서 두 컨벡스헐이 교차되는지 확인하기 위하여 모든 변들에 대해서 교차 여부를 검사하면 됩니다.

두 선분이 교차하는 그림이 있을 때, 교차하는지 확인하려면 ccw(A,B,C)와 ccw(A,B,D)가 서로 다른 방향을 가지는지 확인하면 됩니다. 즉 ccw(A,B,C) * ccw(A,B,D) < 0이면 두 선분이 교차한다는 것을 알 수 있습니다.
하지만 그림 2번에서는, ccw(A,B,C) * ccw(A,B,D) < 0이더라도, 두 선분은 교차하지 않습니다.
이를 검사하기 위해 다른 선분에 대해서도 ccw를 구해주면 됩니다.
ccw(C, D, A) * ccw(C,D,B) > 0이기 때문에 두 선분은 교차하지 않습니다.
따라서 ccw(A,B,C) * ccw(A,B,D) < 0 && ccw(C, D, A) * ccw(C,D,B) < 0 이면, 두 선분은 교차한다고 볼 수 있습니다.
다음으로 그림 3번처럼 두 선분 A-B와 C-D가 일직선으로 놓여져있어서 ccw(A,B,C) * ccw(A,B,D) == 0 && ccw(C,D,A) * ccw(C,D,B) == 0인 상황이 있을 수 있습니다.
두 직선이 서로 떨어져있다면 점을 분리할 수 있지만, 서로 겹쳐져있다면 점을 분리할 수 없습니다.
이 경우에는 두 직선이 겹치는지 알기 위해 C <= B && A <= D이라면 교차한다고 보게 됩니다.
또, 4번과 같이 선분 위의 한 점에서 다른 선분의 끝 점이 겹치는 상황이 있을 수 있습니다. 저 경우에도 분리할 수 없으므로 교차한다고 판별이 됩니다.
그림같은 상황에서는, ccw(A,B,C) > 0, ccw(A,B,D) == 0, ccw(C,D,A) < 0, ccw(C,D,B) > 0이므로,
ccw(A,B,C) * ccw(A,B,D) == 0,
ccw(C,D,A) * ccw(C,D,B) < 0이 나오게 됩니다.
즉, 두 ccw곱이 모두 음수일 때 뿐만 아니라 하나가 0일 때도 교차로 판별이 됩니다.
​
정리하면,
ccw(A,B,C) * ccw(A,B,D) == 0 && ccw(C,D,A) * ccw(C,D,B) == 0 일 때,
    (C <= B && A <= D)가 참이면 교차 // (A < B, C < D)
그렇지 않다면,
    (ccw(A,B,C) * ccw(A,B,D) <= 0 && ccw(C, D, A) * ccw(C,D,B) <= 0)가 참이면 교차
입니다.
*/