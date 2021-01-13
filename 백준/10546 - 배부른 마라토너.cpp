#include <iostream>
#include <map>
using namespace std;
int n;
string s;
map<string, int> m;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) { // map에 삽입
		cin >> s;
		auto item = m.find(s);
		if (item == m.end()) m.insert({ s, 1 });
		else (item->second)++; // 중복 이름
	}
	for (int i = 1; i < n; i++) { // 요소있으면 -1
		cin >> s;
		auto item = m.find(s);
		item->second--;
	}
	for (auto it = m.begin(); it != m.end(); it++) {
		if (it->second != 0) { // 안나온게 있으면 출력
			cout << it->first;
			break;
		}
	}
}