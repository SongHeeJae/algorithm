#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s;
int alp[26] = { 0, };
int n, ans = 0, m = 9;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		int c = 1;
		for (int j = s.length() - 1; j >= 0; j--, c*=10) alp[s[j] - 'A'] += c;
	}
	sort(alp, alp+26);
	for (int i = 25; alp[i]; i--) ans += alp[i] * m--;
	cout << ans;
}