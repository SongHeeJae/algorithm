#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;

const double PI = 3.1415926535;
const double ROUND = 0.5;

int n, l, x, y;
double ans = 0;
vector<pair<int, int>> pos, hull;

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

double getDist(int x1, int y1, int x2, int y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
	scanf("%d %d", &n, &l);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		pos.push_back({ x, y });
	}

	sort(pos.begin(), pos.end(), compAscXAscY);
	sort(pos.begin() + 1, pos.end(), comp);

	hull.push_back(pos[0]);
	hull.push_back(pos[1]);

	for (int i = 2; i < pos.size(); i++) {
		while (hull.size() >= 2) {
			pair<int, int> a = hull.back();
			hull.pop_back();
			pair<int, int> b = hull.back();
			int res = ccw(pos[i].first, pos[i].second, a.first, a.second, b.first, b.second);
			if (res < 0) {
				hull.push_back(a);
				break;
			}
		}
		hull.push_back(pos[i]);
	}

	for (int i = 1; i < hull.size(); i++) {
		ans += getDist(hull[i].first, hull[i].second, hull[i - 1].first, hull[i - 1].second);
	}
	ans += getDist(hull.front().first, hull.front().second, hull.back().first, hull.back().second);
	ans += 2 * PI * l;
	
	printf("%d", int(ans + ROUND));
}

/*
풀이 : https://blog.naver.com/gmlwo308/222461692294

방벽의 길이는, 컨벡스헐의 둘레 + 모서리 부분마다 생기는 호의 길이의 합으로 구할 수 있습니다.

오각형의 컨벡스헐이 있고 모서리마다 삐져나온 부분의 길이가 L이라고 할 때, 빨간색 부분이 방벽으로 세워지는 호가 됩니다.
해당하는 부분의 길이를 구해주는 방법은 다음과 같습니다.
N각형의 컨벡스헐이 있으면, N개의 호가 형성이 됩니다.
또, N각형의 내각의 합은 180 * (N - 2)가 됩니다.
각 호의 각도를 세타1, 세타2, ..., 세타N이라고 할때,
각각의 각도의 마주보는 각은 (180 - 세타1), (180 - 세타2), ..., (180 - 세타N)이 되고, 이것은 내각의 합입니다.
따라서,
180 * (N - 2)
= (180 - 세타1) + (180 - 세타2) + ... + (180 - 세타N)
= 180 * N - (세타1 + 세타2 + ... + 세타N) 이므로,
180 * N - 360 = 180 * N - (세타1 + 세타2 + ... + 세타N)
(세타1 + 세타2 + ... + 세타N) = 360 이 되면서, 모든 세타 각의 합은 360도가 됩니다.
또한, 호의 반지름은 거리 L입니다.
이를 통해, 모든 호들의 길이 합은 반지름이 L인 원의 둘레인 2 * 파이 * L이 됩니다.
*/