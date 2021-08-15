#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int t, n;
ll x, y;
vector<pair<int, pair<ll, ll>>> pos;

// 시계 음수, 반시계 양수, 일직선 0
ll ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	return (x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1);
}

bool compAscXAscY(pair<int, pair<ll, ll>>& a, pair<int, pair<ll, ll>>& b) {
	if (a.second.first == b.second.first) return a.second.second < b.second.second;
	else return a.second.first < b.second.first;
}

// 기준점에서 시계 반대 방향으로 정렬
bool comp(pair<int, pair<ll, ll>>& a, pair<int, pair<ll, ll>>& b) {
	ll res = ccw(pos[0].second.first, pos[0].second.second, a.second.first, a.second.second, b.second.first, b.second.second);
	if (res == 0) {
		if (a.second.first == b.second.first) return a.second.second < b.second.second;
		else return a.second.first < b.second.first;
	}
	else {
		return res > 0;
	}
}

int main() {
	scanf("%d", &t);
	while (t--) {
		pos.clear();
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%lld %lld", &x, &y);
			pos.push_back({ i, { x, y } });
		}

		sort(pos.begin(), pos.end(), compAscXAscY);
		sort(pos.begin() + 1, pos.end(), comp);

		int i = n - 2;
		for (; i >= 0
			&& ccw(pos[0].second.first, pos[0].second.second,
			pos[i].second.first, pos[i].second.second,
			pos[i + 1].second.first, pos[i + 1].second.second) == 0; i--);

		for (int j = 0; j <= i; j++) {
			printf("%d ", pos[j].first);
		}
		for (int j = n - 1; j > i; j--) {
			printf("%d ", pos[j].first);
		}
		printf("\n");
	}
}

/*
가장 상단 좌측 좌표를 기준점으로 하고, 기준점의 반시계 방향으로 다른 좌표들을 정렬해줍니다.
정렬된 좌표들을 순서대로 선택하되, 다각형으로 만들기 위해 마지막에 일직선으로 되어있는 좌표들부터는 역순으로 선택해주면 됩니다.
*/