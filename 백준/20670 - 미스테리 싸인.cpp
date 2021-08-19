#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int n, m, k;

// 시계 음수, 반시계 양수, 일직선 0
int ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	ll cw = (x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1);
	if (cw > 0) return 1;
	if (cw < 0) return -1;
	return 0;
}

// outer는 반시계 방향으로 들어가있음
// 0번째를 기준점으로 다른 모든 꼭짓점과의 반직선을 그리고,
// p가 어떤 반직선 범위 안에 포함되는지 이분 탐색으로 찾아낼 것
bool isInside(vector<pair<ll, ll>>& outer, pair<ll, ll>& p) {
	
	int sz = outer.size();
	if (sz <= 2) return false;

	// 첫번째 반직선과 마지막 반직선 사이에 포함되지 않는 경우 return false
	if (ccw(outer[0].first, outer[0].second, outer[1].first, outer[1].second, p.first, p.second) < 0
		|| ccw(outer[0].first, outer[0].second, outer[sz - 1].first, outer[sz - 1].second, p.first, p.second) > 0)
		return false;

	int l = 1, r = n - 1; // 기준점 양 옆의 정점
	while (r - l != 1) {
		// 기준점0 -> 점 m -> 점 p의 ccw를 구한다.
		int m = (l + r) / 2;
		int cw = ccw(outer[0].first, outer[0].second, outer[m].first, outer[m].second, p.first, p.second);
		if (cw > 0) {
			l = m;
		}
		else {
			r = m;
		}
	}

	// (기준점 -> l)과 (기준점 -> (l + 1)) 반직선 사이에 p가 있음
	return ccw(outer[l].first, outer[l].second, outer[r].first, outer[r].second, p.first, p.second) > 0;
}

void inputPos(int size, vector<pair<ll, ll>>& pos) {
	ll x, y;
	for (int i = 0; i < size; i++) {
		cin >> x >> y;
		pos.push_back({ x, y });
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<pair<ll, ll>> a, b, s;
	
	cin >> n >> m >> k;
	
	inputPos(n, a); 
	inputPos(m, b);
	inputPos(k, s);

	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (!isInside(a, s[i]) || isInside(b, s[i])) {
			cnt++;
		}
	}

	if (cnt == 0) {
		cout << "YES";
	}
	else {
		cout << cnt;
	}
}

/*
풀이 링크 : https://blog.naver.com/gmlwo308/222464130488

반시계 방향으로 주어지는 도형 A와 도형 B의 좌표를 가지고,
싸인을 구성하는 모든 좌표들이 A에는 포함되면서 B에는 포함되지 않는지 확인해주어야합니다.
처음에는 도형 X와 좌표 p가 있을 때, 도형 X의 모든 변에 대해서 좌표 p와의 방향성을 검사하며 포함 여부를 확인해주었습니다.
하지만 이렇게 할 경우, 30만 * (1만 + 1만) = 60억 번의 연산이 필요하면서 시간초과가 나게 되므로,
포함 여부를 빠르게 확인하기 위해 이분 탐색을 이용하였습니다.

육각형이 있을 때, 이 도형의 각 꼭짓점의 번호는 기준점에서 반시계 방향으로 붙어있는 상황입니다.
그리고 기준점 O에서 다른 꼭짓점으로 향하는 반직선을 그려주면, 내부에 있는 검사하고자 하는 좌표는 어떤 반직선과 반직선 사이에 있을 것입니다.
그림에서 좌표 X는 첫번째 반직선과 마지막 반직선 사이에도 포함되지 않습니다.
즉 ccw(O, 1, X) < 0 || ccw(O, n-1, X) > 0이면 도형 내에 포함되지 않습니다.
좌표 Y와 Z는 반직선과 반직선 사이에 있습니다.
어떤 반직선들 사이에 있는지 구하기 위해 이분 탐색을 수행해줍니다.
left = 1, right = n - 1을 초기화해놓고 mid에 있는 반직선의 꼭짓점을 구하여 찾고자하는 좌표 P와의 ccw를 구해줍니다.
ccw(O, mid, P) > 0 이라면 left = mid,
그렇지 않다면 right = mid로 범위를 좁혀나가며
right - left == 1일 때까지 수행해서 어떤 범위에 포함되는지 찾아줍니다.
ccw(left, right, P) > 0이면 도형 내에 포함되고,
그렇지 않다면, 도형 내에 포함되지 않습니다.
*/