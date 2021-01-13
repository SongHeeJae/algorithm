#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	string p, f;
	cin >> p;
	while (n--) {
		cin >> f;
		bool flag = true;
		int i, j, k;
		for (i = 0; p[i] != '*'; i++) {
			if (p[i] != f[i]) {
				flag = false;
				break;
			}
		}
		for (j = f.length() - 1, k = p.length() - 1; p[k] != '*'; j--, k--) {
			if (p[k] != f[j]) {
				flag = false;
				break;
			}
		}
		printf("%s\n", flag ? (i + f.length() - j - 1 > f.length() ? "NE" : "DA") : "NE");
	}
}