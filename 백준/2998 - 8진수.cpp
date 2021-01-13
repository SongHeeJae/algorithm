#include <iostream>
using namespace std;

int main() {
	string n;
	int ans[34] = { 0, }, c = 0;
	cin >> n;
	while (n.length() % 3 != 0) n = "0" + n;
	for (int i = n.length() - 1; i >= 0; i -= 3)
		ans[c++] = (n[i] - '0') + (n[i - 1] - '0') * 2 + (n[i - 2] - '0') * 4;
	while(c--) printf("%d", ans[c]);
}