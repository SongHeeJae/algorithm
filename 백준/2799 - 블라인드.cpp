#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, blind[5] = { 0, };
	string s;
	cin >> n >> m;
	getline(cin, s);
	for (int i = 0; i < n; i++) {
		vector<int> t(m, 0);
		getline(cin, s);
		for (int j = 0; j < 4; j++) {
			getline(cin, s);
			for (int k = 1; k < s.length(); k+=5) {
				if (s[k] == '*')
					t[k/5]++;
			}
		}
		for (int j = 0; j < m; j++) blind[t[j]]++;
	}
	getline(cin, s);
	for (int i = 0; i < 5; i++) cout << blind[i] << " ";
}
