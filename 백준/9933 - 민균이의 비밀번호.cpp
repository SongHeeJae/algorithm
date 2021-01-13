#include <iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int main() {
	set<string> words;
	int n;
	scanf("%d", &n);
	string s, temp, ans;
	while (n--) {
		cin >> s;
		temp = s;
		reverse(temp.begin(), temp.end());
		words.insert(s);
		if (words.find(temp) != words.end()) ans = temp;
	}
	cout << ans.length() << " " << ans[ans.length() / 2] << "\n";
}