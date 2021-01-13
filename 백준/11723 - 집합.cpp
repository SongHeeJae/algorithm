#include <iostream>
#include <set>
#include <string>
using namespace std;
int m, n;
string s;
set<int> st;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> m;
	while (m--) {
		cin >> s;
		if (s == "all") {
			s.clear();
			for (int i = 1; i <= 20; i++) st.insert(i);
		}
		else if (s == "empty") st.clear();
		else {
			cin >> n;
			if (s == "remove") st.erase(n);
			else if (s == "check") {
				if (st.find(n) != st.end()) cout << "1\n";
				else cout << "0\n";
			}
			else if (s == "toggle") {
				if (st.find(n) != st.end()) st.erase(n);
				else st.insert(n);
			}
			else st.insert(n);
		}
	}
}
