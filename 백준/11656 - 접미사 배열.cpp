#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	vector<string> s;
	string word;
	cin >> word;
	do {
		s.push_back(word);
		word = word.substr(1);
	} while (word.length() != 1);
	s.push_back(word);
	std::sort(s.begin(), s.end());
	for (string ss : s) cout << ss << "\n";
}

