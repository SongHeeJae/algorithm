#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	int m = 987654321;
	for (int i = 0; i <= b.length() - a.length(); i++) {
		int c = 0;
		for (int j = 0; j < a.length(); j++) {
			if (a[j] != b[i + j]) c++;
		}
		m = min(c, m);
	}
	cout << m << "\n";
}

