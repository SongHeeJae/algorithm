#include <iostream>
#include <string>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	int i = 0, j = 0, f = 0;
	for (i = 0; i < a.length(); i++) {
		for (j = 0; j < b.length(); j++)
			if (a[i] == b[j]) {
				f = 1;
				break;
			}
		if (f) break;
	}

	for (int k = 0; k < b.length(); k++) {
		if (k == j) cout << a;
		else
			for (int l = 0; l < a.length(); l++)
				cout << (l == i ? b[k] : '.');
		cout << "\n";
	}
}