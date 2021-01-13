#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	scanf("%d %d\n", &n, &m);
	set<string> list;
	vector<string> result;
	while (n--) {
		string s;
		cin >> s;
		list.insert(s);
	}
	while (m--) {
		string s;
		cin >> s;
		if (list.find(s) != list.end())
			result.push_back(s);
	}
	cout << result.size() << "\n";
	std::sort(result.begin(), result.end());
	for (string s : result) cout << s << "\n";
}