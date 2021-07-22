#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string s;
bool chk[100] = { false };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		string res = "z";
		int idx = 0;
		for (int j = 0; j < s.size(); j++) {
			if (chk[j]) continue;
			string t = "";
			chk[j] = true;
			for (int k = 0; k < s.size(); k++) {
				if (chk[k]) t.push_back(s[k]);
			}
			chk[j] = false;
			if (res > t) {
				res = t;
				idx = j;
			}
		}
		chk[idx] = true;
		cout << res << "\n";
	}
}

/*
각 문자열 길이마다 하나씩 문자를 추가하며, 사전순으로 제일 빠른 문자열을 출력하여 추가한 인덱스는 방문 표시를 해주었습니다.
*/