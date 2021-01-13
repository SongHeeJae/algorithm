#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, b[10] = { 0, };
	scanf("%d", &n);
	if (n == 0) printf("1\n");
	else {
		while (n != 0) {
			b[n % 10]++;
			n /= 10;
		}
		int m = -1;
		for (int i = 0; i < 10; i++) {
			if (i == 6 || i == 9) continue;
			m = max(m, b[i]);
		}
		printf("%d\n", max(m, int(((b[6] + b[9]) / 2.0) + 0.9999)));
	}
}