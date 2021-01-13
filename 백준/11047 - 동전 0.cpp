#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k, coin[10], c = 0;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) scanf("%d", &coin[i]);
	--n;
	while (n >= 0 && k != 0) {
		if (k / coin[n] > 0) {
			k -= coin[n];
			c++;
		}
		else n--;
	}
	printf("%d\n", c);
}