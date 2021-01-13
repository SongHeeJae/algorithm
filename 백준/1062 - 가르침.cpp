#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int word(vector<string>& s, bool *alp, int k, int m, int count, int index) {

	if (count == k) {
		int c = 0;
		for (string ss : s) {
			bool f = true;
			for (int i = 4; i < ss.length() - 4; i++)
				if (!alp[ss[i]]) {
					f = false;
					break;
				}
			if (f) c++;
		}
		return c;
	}
	
	int res = -1;
	for (int i = index; i <= 'z'; i++) {
		if (!alp[i]) {
			alp[i] = true;
			res = max(word(s, alp, k, res, count + 1, i + 1), res);
			alp[i] = false;
		}
	}
	return res;
}

int main() {
	int n, k;
	bool alp['z' + 1] = { false, };
	alp['a'] = alp['n'] = alp['t'] = alp['i'] = alp['c'] = true;

	scanf("%d %d", &n, &k);
	vector<string> s(n);
	for (int i = 0; i < n; i++) cin >> s[i];
	if (k < 5) cout << "0\n";
	else if (k == 26) cout << n << "\n";
	else cout << word(s, alp, k - 5, -1, 0, 'a') << "\n";
}