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
	int c = 0, j = 0; // j 는 p의 인덱스
	for (int i = 0; i < s.length(); i++) {
		while (j > 0 && s[i] != p[j])
			j = pi[j - 1]; 
		if (s[i] == p[j]) {
			if (j == p.length() - 1) {
				c++;
				j = 0;
			}
			else j++;
		}
	}
	return c;
}

int main() {
	string s, p;
	getline(cin, s);
	getline(cin, p);
	cout << kmp(s, p) << "\n";
}