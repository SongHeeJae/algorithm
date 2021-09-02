#include <iostream>
using namespace std;

int g, s, ans = 0;
int wcnt['z' + 1] = { 0 };
int scnt['z' + 1] = { 0 };
string W, S;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> g >> s >> W >> S;
	for (int i = 0; i < g; i++) {
		wcnt[W[i]]++;
		scnt[S[i]]++;
	}

	for (int i = g; ; i++) {
		bool same = true;
		for (int j = 'A'; j <= 'z'; j++) {
			if (scnt[j] != wcnt[j]) same = false;
		}
		ans += same;

		if (i == s) break;

		scnt[S[i - g]]--;
		scnt[S[i]]++;
	}
	cout << ans;
}

/*
W의 문자 개수를 카운팅해둔 뒤,
S에서 W의 길이만큼 자른 부분 문자열의 문자 개수와 일치하는지 확인해주었습니다.
*/