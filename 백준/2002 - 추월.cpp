#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<pair<string, int>> arr; // int는 차량 위치 인덱스
	map<string, int> m; // int는 arr에서의 index
	int n, cnt = 0;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		arr.push_back({ s, i });
		m.insert({ s, i });
	}
	int c = 0; // 추월한 차
	for (int i = 0; i < n; i++) {
		cin >> s;
		auto it = m.find(s);
		int idx = it->second;
		if (i < arr[idx].second) {
			c++;
			while (idx--) arr[idx].second += 1;
		}
	}
	cout << c;
}