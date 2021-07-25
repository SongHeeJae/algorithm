#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, a, b, ans = 0;
vector<pair<int, int>> arr;

bool comp(pair<int, int>& a, pair<int, int>& b) {
	if (a.first == b.first) return a.second < b.second;
	else return a.first < b.first;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	while (n--) {
		cin >> a >> b;
		arr.push_back({ a, 1 });
		arr.push_back({ b, -1 });
	}

	sort(arr.begin(), arr.end(), comp);

	int cnt = 0;
	for (int i = 0; i < arr.size(); i++) {
		cnt += arr[i].second;
		ans = max(ans, cnt);
	}
	cout << ans;
}

/*
시작 시간에는 +1, 끝나는 시간에는 -1의 가중치를 둔 뒤, 
시간 오름차순, 끝나는 시간 우선으로 정렬하여 가중치 합의 최댓값을 구해주었습니다.
*/