#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int s = 0, a;
	for (int i = 0; i < 10; i++) {
		cin >> a;
		s += a;
		if (s >= 100) {
			cout << (s - 100 <= 100 - s + a ? s : s - a);
			return 0;
		}
	}
	cout << s;
}