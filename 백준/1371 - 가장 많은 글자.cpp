#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int alp['z' + 1] = { 0, };
	string s;
	while (getline(cin, s)) {
		for (int i = 0; i < s.length(); i++) alp[s[i]]++;
	}
	int max = -1;
	for (int i = 'a'; i <= 'z'; i++) max = alp[i] > max ? alp[i] : max;
	for (int i = 'a'; i <= 'z'; i++) 
		if (alp[i] == max && alp[i] > 0) printf("%c", i);
	
}