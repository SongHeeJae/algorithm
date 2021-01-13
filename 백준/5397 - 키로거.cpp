#include <iostream>
#include <string>
#include <deque>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	while (n--) {
		string s;
		deque<char> ans;
		cin >> s;
		int idx = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '<') {
				idx = idx ? idx - 1 : 0;
			}
			else if (s[i] == '>') {
				idx = idx == ans.size() ? idx : idx + 1;
			}
			else if (s[i] == '-') {
				if (idx != 0) {
					ans.erase(ans.begin() + idx - 1);
					idx--;
				}
			}
			else {
				if (idx == ans.size()) ans.push_back(s[i]);
				else ans.insert(ans.begin() + idx, s[i]);
				idx++;
			}
		}
		for (char c : ans) cout << c;
		cout << "\n";
	}
}