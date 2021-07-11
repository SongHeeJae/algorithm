#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, h, o, d, ans = 0;
pair<int, int> ho[100000];
vector<pair<int, int>> arr;

bool compare(pair<int, int>& a, pair<int, int>& b) {
	if (a.first == b.first) return a.second > b.second;
	else return a.first < b.first;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &h, &o);
		if (h > o) ho[i] = { o, h };
		else ho[i] = { h, o };
	}
	scanf("%d", &d);
	for (int i = 0; i < n; i++) {
		if (ho[i].second - ho[i].first <= d) {
			arr.push_back({ ho[i].first, -1 });
			arr.push_back({ ho[i].second - d, 1 });
		}
	}
	sort(arr.begin(), arr.end(), compare);
	int cnt = 0;
	for (int i = 0; i < arr.size(); i++) {
		cnt += arr[i].second;
		ans = max(ans, cnt);
	}
	printf("%d", ans);
}

/*
​집과 사무실의 위치를 하나의 선분으로 봤을 때, 도착 지점을  -d만큼 이동시켜 준 뒤, 겹치는 선분의 개수를 구해주었습니다.
*/