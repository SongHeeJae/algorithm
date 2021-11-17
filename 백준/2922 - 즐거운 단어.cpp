#include <iostream>
using namespace std;

typedef long long ll;

string s;
ll cnt = 0;

bool isMo(char ch) {
	return ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
}

bool isJa(char ch) {
	return !isMo(ch);
}

void dfs(int idx, int mo, int ja, bool l, ll c) {
	if (mo >= 3 || ja >= 3) return;
	if (idx == s.size()) {
		if (l) cnt += c;
		return;
	}

	if (s[idx] == '_') {
		dfs(idx + 1, mo + 1, 0, l, c * 5);
		dfs(idx + 1, 0, ja + 1, l, c * 20);
		dfs(idx + 1, 0, ja + 1, true, c);
	}
	else {
		dfs(idx + 1, isMo(s[idx]) ? mo + 1 : 0, isJa(s[idx]) ? ja + 1 : 0, l || s[idx] == 'L', c);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;
	dfs(0, 0, 0, false, 1);
	cout << cnt;
}

/*
s[idx]가 알파벳이라면, 연속된 자음과 모음 개수를 업데이트하고, 알파벳이 'L'인지 확인해줍니다.
확정된 알파벳이므로 지금 흐름에서 경우의 수의 변동은 없습니다.

s[idx]가 '_'이라면, 세 가지 상황으로 나뉘게 됩니다.
1. '_'가 모음인 경우
연속된 모음 개수를 업데이트해주고, 연속된 자음 개수는 0으로 초기화해줍니다.
'L' 포함 여부는 그대로 전달되고, 모음은 5개이므로 경우의 수는 * 5가 됩니다.
2. '_'가 'L'이 아닌 자음인 경우
연속된 자음 개수를 업데이트해주고, 연속된 모음 개수는 0으로 초기화해줍니다.
'L' 포함 여부는 그대로 전달되고, 'L'을 제외한 자음은 20개이므로 경우의 수는 * 20이 됩니다.
3. '_'가 'L'인 경우
연속된 자음 개수를 업데이트해주고, 연속된 모음 개수는 0으로 초기화해줍니다.
'L' 포함 여부는 true로 고정되고, 경우의 수의 변동은 없습니다.
*/