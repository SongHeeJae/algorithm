#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> getPi(string p) {
	int m = p.length(), j = 0;
	vector<int> pi(m, 0);
	for (int i = 1; i < m; i++) {
		while (j > 0 && p[i] != p[j])
			j = pi[j - 1];
		if (p[i] == p[j]) pi[i] = ++j;
	}
	return pi;
}

int kmp(string s, string p) {
	vector<int> pi = getPi(p);
	int n = s.length(), m = p.length(), j = 0;
	for (int i = 0; i < n; i++) {
		while (j > 0 && s[i] != p[j])
			j = pi[j - 1];
		if (s[i] == p[j]) {
			if (j == m - 1) {
				return 1;
				j = pi[j];
			}
			else j++;
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s, p;
	cin >> s >> p;
	cout << kmp(s, p);
}