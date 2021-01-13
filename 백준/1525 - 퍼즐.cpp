#include <iostream>
#include <string>
#include <queue>
#include <set>
using namespace std;

string s;
int d[] = {1,-1,-3,3}, a;
set<string> st;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < 9; i++) {
		cin >> a;
		s += a+'0';
	}

	queue<pair<string, int>> q;
	q.push({ s, 0 });
	st.insert(s);
	while (!q.empty()) {
		s = q.front().first;
		int t = q.front().second;

		if (s == "123456780") {
			cout << t;
			return 0;
		}
		for (int i = 0; i < 9; i++)
			if (s[i] == '0') {
				a = i;
				break;
			}
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nd = a + d[i];
			if (nd < 0 || nd > 8) continue;
			if ((i == 0 || i==1 ) && a / 3 != nd / 3) continue;
			
			char c = s[a];
			s[a] = s[nd];
			s[nd] = c;

			if (st.find(s) == st.end()) {
				st.insert({s});
				q.push({ s, t + 1 });
			}
			s[nd] = s[a];
			s[a] = c;	
		}
	}
	cout << -1;
}