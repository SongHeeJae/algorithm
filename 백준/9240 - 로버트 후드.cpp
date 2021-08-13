#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;

int n, x, y;
vector<pair<int, int>> pos;
vector<pair<int, int>> hull;
stack<pair<int, int>> stk;

// 시계 음수, 반시계 양수, 일직선 0
int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
	return (x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1);
}

// x좌표 오름차순, y좌표 오름차순 정렬
// 가장 상단 왼쪽이 기준점
bool compAscXAscY(pair<int, int>& a, pair<int, int>& b) {
	if (a.first == b.first) return a.second < b.second;
	else return a.first < b.first;
}

// 기준점에서 시계 반대 방향으로 정렬
bool comp(pair<int, int>& a, pair<int, int>& b) {
	int res = ccw(pos[0].first, pos[0].second, a.first, a.second, b.first, b.second);
	if (res == 0) { // 일직선인 경우 상단 좌측 순
		if (a.first == b.first) return a.second < b.second;
		else return a.first < b.first;
	}
	else {
		// 기준점, a, b가 반시계 방향을 이루도록 정렬
		return res > 0;
	}
}

int getDist(int x1, int y1, int x2, int y2) {
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		pos.push_back({ x, y });
	}

	sort(pos.begin(), pos.end(), compAscXAscY);
	sort(pos.begin() + 1, pos.end(), comp);

	stk.push(pos[0]);
	stk.push(pos[1]);

	for (int i = 2; i < pos.size(); i++) {
		while (stk.size() >= 2) {
			pair<int, int> a = stk.top();
			stk.pop();
			pair<int, int> b = stk.top();
			int res = ccw(pos[i].first, pos[i].second, a.first, a.second, b.first, b.second);
			if (res < 0) {
				stk.push(a);
				break;
			}
		}
		stk.push(pos[i]);
	}

	while (!stk.empty()) {
		hull.push_back(stk.top()); // hull에는 시계 방향으로 들어가게됨
		stk.pop();
	}

	int mx = 0;
	int j = 1;
	for (int i = 0; i < hull.size(); i++) {
		int ni = (i + 1) % hull.size();
		while (1) {
			int nj = (j + 1) % hull.size();
			int nx = hull[ni].first + (hull[nj].first - hull[j].first); // ni에 연결된 좌표로
			int ny = hull[ni].second + (hull[nj].second - hull[j].second); // 바꿔줌
			int res = ccw(hull[i].first, hull[i].second, hull[ni].first, hull[ni].second, nx, ny);
			if (res >= 0) break; // 시계 방향이 아니게 되면 거리 구해줌
			j = nj;
		}
		int d = getDist(hull[i].first, hull[i].second, hull[j].first, hull[j].second);
		if (d > mx) {
			mx = d;
		}
	}
	printf("%lf", sqrt(mx));
}

/*
풀이는 아래 링크와 같습니다.
https://blog.naver.com/gmlwo308/222461648798
*/