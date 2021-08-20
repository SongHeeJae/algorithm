#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, pii> piiii;

int n;
piiii lines[3000];
int p[3000], c[3000] = { 0 };

// 시계 음수, 반시계 양수, 일직선 0
int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
	int cw = (x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1);
	if (cw > 0) return 1;
	if (cw < 0) return -1;
	return 0;
}

// a-b, c-d가 교차하는지 확인
// ccw(a,b,c) * ccw(a,b,d) == 0 && ccw(b,d,a) * ccw(b,d,c) == 0이면
// a--c--b--d 형태일 때 교차했다고 봄
// 그렇지 않으면,
// ccw(a,b,c) * ccw(a,b,d) <= 0 && ccw(b,d,a) * ccw(b,d,c) <= 0이면 교차
bool isCross(pii a, pii b, pii c, pii d) {
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

int findParent(int x) {
	if (p[x] == x) return x;
	else return p[x] = findParent(p[x]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> lines[i].first.first >> lines[i].first.second
			>> lines[i].second.first >> lines[i].second.second;
		p[i] = i;
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int pi = findParent(i);
			int pj = findParent(j);
			if (isCross(lines[i].first, lines[i].second, lines[j].first, lines[j].second)) {
				if (pi != pj) {
					p[pi] = pj;
				}
			}
		}
	}

	int mx = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		int pi = findParent(i);
		if (pi == i) cnt++;
		mx = max(mx, ++c[pi]);
	}

	cout << cnt << "\n" << mx;
}

/*
유니온파인드를 이용하여 두 선분이 교차한다면, 같은 그룹으로 묶어주었습니다.
선분이 교차하는지 판별하는 방법은 아래 링크의 두 번째 그림에 나와있습니다.
https://blog.naver.com/gmlwo308/222462695063
*/