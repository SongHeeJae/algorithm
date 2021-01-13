#include <iostream>
#include <vector>
#include <set>
using namespace std;
int r, c, cnt = 0, f;
vector<string> str(1000);
char ch;
set<string> st;
string s;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) {
			cin >> ch;
			str[j].push_back(ch);
		}
			

	for (int i = 1; i < r; i++) {
		f = 0;
		st.clear();
		for (int j = 0; j < c; j++) {
			s = str[j].substr(i);
			if (st.find(s) == st.end()) st.insert(s);
			else {
				f = 1;
				break;
			}
		}
		if (f) break;
		cnt++;
	}
	cout << cnt;
}