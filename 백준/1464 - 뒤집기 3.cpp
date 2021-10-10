#include <iostream>
#include <algorithm>
using namespace std;
string str, ans = "";
int main() {
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		ans = min(ans + str[i], str[i] + ans);
	}
	cout << ans;
}