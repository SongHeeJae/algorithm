#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, a, b, ans = 1, used = 0;
vector<pair<int, int>> t;
bool compare(pair<int, int>& a, pair<int, int>& b) {
	if (a.first == b.first) return a.second > b.second;
	else return a.first < b.first;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n && scanf("%d %d", &a, &b); i++) {
		t.push_back({ a, 0 });
		t.push_back({ b, 1 });
	}
	sort(t.begin(), t.end(), compare);
	for (int i = 0; i < t.size(); i++) {
		t[i].second ? used-- : used++;
		ans = max(used, ans);
	}
	printf("%d", ans);
}

/*
1. 시간 빠른 순
2. 종료 이벤트 우선
위 두 조건으로 시작 이벤트와 종료 이벤트를 정렬 한 뒤, 사용해야할 강의실의 개수를 계산해주었습니다.
*/