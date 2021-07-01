#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, a, b, c, ans = 0, cnt = 0;
vector<pair<int, int>> arr;

bool comp(pair<int, int>& a, pair<int, int>& b) {
	if (a.first == b.first) return a.second < b.second;
	else return a.first < b.first;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &a, &b, &c);
		arr.push_back({ b, 1 });
		arr.push_back({ c, -1 });
	}
	sort(arr.begin(), arr.end(), comp);
	for (int i = 0; i < arr.size(); i++) {
		cnt += arr[i].second;
		ans = max(ans, cnt);
	}
	printf("%d", ans);
}

/*
강의 시작 시간에는 +1, 강의 종료 시간에는 -1의 가중치를 주어서 배열을 만든 뒤,
시간 오름차순, 가중치 오름차순으로 정렬합니다.
최소 사용해야하는 강의실의 수는 가중치 누적합의 최댓값입니다.
*/