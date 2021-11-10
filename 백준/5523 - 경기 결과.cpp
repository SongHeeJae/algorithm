#include <iostream>
using namespace std;
int n, a, b, c1 = 0, c2 = 0;
int main() {
	scanf("%d", &n);
	while (n--) {
		scanf("%d %d", &a, &b);
		if (a > b) c1++;
		else if (a < b) c2++;
	}
	printf("%d %d", c1, c2);
}