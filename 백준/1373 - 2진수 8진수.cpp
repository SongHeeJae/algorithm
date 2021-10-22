#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

string s, ans = "";
map<string, char> m = { {"000", '0'}, {"001", '1'}, {"010", '2'},
	{"011", '3'}, {"100", '4'}, {"101", '5'}, {"110", '6'}, {"111", '7'},
	{"0", '0'}, {"1", '1'}, {"10", '2'}, {"11", '3'} };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;
	int i = s.size() - 3;
	for (; i >= 0; i -= 3) ans.push_back(m[s.substr(i, 3)]);
	if(i != -3) ans.push_back(m[s.substr(0, i + 3)]);
	reverse(ans.begin(), ans.end());
	cout << ans;
}
/*
뒤에서부터 세 자리씩 슬라이싱하며, 대응되는 8진수를 구해주었습니다.
*/