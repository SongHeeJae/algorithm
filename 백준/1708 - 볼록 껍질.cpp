#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
typedef long long ll;
using namespace std;

int n;
long long x, y;
vector<pair<ll, ll>> pos;
stack<pair<ll, ll>> stk;

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
	if (res == 0) { // 일직선인 경우 상단 좌측 순
		if (a.first == b.first) return a.second < b.second;
		else return a.first < b.first;
	}
	else {
        // 기준점, a, b가 반시계 방향을 이루도록 정렬
		return res > 0;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &x, &y);
		pos.push_back({ x, y });
	}

	sort(pos.begin(), pos.end(), compAscXAscY);
	sort(pos.begin() + 1, pos.end(), comp);

	stk.push(pos[0]);
	stk.push(pos[1]);

	for (int i = 2; i < pos.size(); i++) {
		while (stk.size() >= 2) {
			pair<ll, ll> a = stk.top();
			stk.pop();
			pair<ll, ll> b = stk.top();
			ll res = ccw(pos[i].first, pos[i].second, a.first, a.second, b.first, b.second);
			if (res < 0) {
				stk.push(a);
				break;
			}
		}
		stk.push(pos[i]);
	}

	printf("%d", stk.size());
}

/*
이 문제를 풀기 위해 아래 문제의 개념을 먼저 익혔습니다.
https://www.acmicpc.net/problem/11758

세 개의 정점으로 연결된 선분이 시계 방향인지, 반시계 방향인지 알면 볼록 껍질을 이루는 점들을 구할 수 있습니다.
1. 가장 바깥쪽에 있는 기준점을 하나 구해줍니다. x좌표 오름차순, y좌표 오름차순으로 정렬 하여 가장 상단의 왼쪽에 있는 좌표를 구해주었습니다.
2. 기준점을 제외한 나머지 좌표들을 기준 점과 만들어내는 방향이 반시계 방향을 이루도록 재정렬해줍니다. 기준점과 두 개의 좌표가 일직선을 이룬다면, 기준 점에 가까운 좌표 우선(상단 좌측 순)으로 정렬해주었습니다. 
3. 정렬된 첫번째 좌표(기준점)와 두번째 좌표를 스택에 담아줍니다.
4. 스택에서 두 개의 좌표 a와 b를 꺼내서 다음 좌표와 이루는 각이 시계 방향(점들을 감싸는 기준 방향)이라면, b와 a와 다음 좌표를 순서대로 스택에 담아줍니다.
5. 반시계 방향이었다면, a를 제외하여 b를 다시 스택에 담아주고 각이 시계 방향을 이룰 때까지 검사해줍니다.
6. 이어서 다음 좌표를 검사해줍니다.
7. 결국 스택에는 볼록 껍질을 이루는 점들의 좌표만 담기게 됩니다.
*/