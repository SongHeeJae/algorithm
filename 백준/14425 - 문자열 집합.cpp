#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, c = 0;
	set<string> s;
	cin >> n >> m;
	while (n--) {
		string temp;
		cin >> temp;
		s.insert(temp);
	}
	while (m--) {
		string temp;
		cin >> temp;
		if (s.find(temp) != s.end()) c++;
	}

	printf("%d\n", c);
}