#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> lines;

int n, a, b, ans = 0;

bool comp(pair<int, int>& a, pair<int, int>& b) {
	if (a.first == b.first) return a.second < b.second;
	else return a.first < b.first;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		lines.push_back({ a, 1 });
		lines.push_back({ b, -1 });
	}
	sort(lines.begin(), lines.end(), comp);
	int cnt = 0;
	for (int i = 0; i < lines.size(); i++) {
		cnt += lines[i].second;
		ans = max(cnt, ans);
	}
	printf("%d", ans);
}

/*
선분에 진입할 때는 1을 더해줍니다.
선분에서 빠져나올 때는 1을 빼줍니다.
각 좌표 순으로 오름차순으로 정렬해서, 겹치는 선분의 개수를 구해주었습니다.
*/