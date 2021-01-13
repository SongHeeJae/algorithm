#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool comp(const string& a, const string& b) {
	return a.length() != b.length() ? a.length() < b.length() : a < b;
}

int main() {
	vector<string> words;
	int n;
	string s;
	scanf("%d", &n);
	while (n-- && cin >> s) words.push_back(s);

	std::sort(words.begin(), words.end(), comp);
	string w = "";
	for (int i = 0; i < words.size(); i++) {
		if(w != words[i]) cout << words[i] << "\n";
		w = words[i];
	}
}