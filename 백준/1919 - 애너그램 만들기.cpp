#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string s1, s2;
	int cs1['z' + 1] = { 0, }, cs2['z' + 1] = { 0, }, c = 0;
	cin >> s1 >> s2;
	for (int i = 0; i < s1.length(); i++) cs1[s1[i]]++;
	for (int i = 0; i < s2.length(); i++) cs2[s2[i]]++;


	for (int i = 'a'; i <= 'z'; i++) {
		if (cs1[i] != 0 && cs2[i] != 0) c += abs(cs1[i] - cs2[i]);
		else c += cs1[i] + cs2[i];
	}
	cout << c << "\n";
}

