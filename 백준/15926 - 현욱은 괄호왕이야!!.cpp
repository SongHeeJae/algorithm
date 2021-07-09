#include <iostream>
#include <algorithm>
using namespace std;

string s;
int n, ans = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> s;
	int lc1 = 0, lc2 = 0, rc1 = 0, rc2 = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') lc1++;
		else {
			lc2++;
			if (lc1 == lc2) {
				ans = max(ans, lc1 + lc2);
			}
			else if (lc1 < lc2) {
				lc1 = lc2 = 0;
			}
		}
		if (s[n - i - 1] == ')') rc1++;
		else {
			rc2++;
			if (rc1 == rc2) {
				ans = max(ans, rc1 + rc2);
			}
			else if (rc1 < rc2) {
				rc1 = rc2 = 0;
			}
		}
	}
	cout << ans;
}

/*
왼쪽에서 시작했을 때와 오른쪽에서 시작했을 때의 올바른 괄호 문자열의 최대 길이를 구해주었습니다.
*/