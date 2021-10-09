#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

string t;
unordered_map<string, int> tree;
vector<pair<string, double>> sorted;
int cnt = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (!getline(cin, t).eof()) {
		auto find = tree.find(t);
		if (find != tree.end()) find->second++;
		else tree.insert({ t, 1 });
		cnt++;
	}

	for (auto& it : tree) {
		sorted.push_back({ it.first, it.second * 100.0 / cnt });
	}

	sort(sorted.begin(), sorted.end());

	cout << fixed;
	cout.precision(4);
	for (auto& s : sorted) {
		cout << s.first << " " << s.second << "\n";
	}
}

/*
unordered_map으로 중복을 제거하며, 각 나무의 개수를 세주었습니다.
*/