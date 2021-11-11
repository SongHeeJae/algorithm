#include <iostream>
using namespace std;
int t, n;
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		printf("Pairs for %d: ", n);
		if (n > 2) {
			printf("%d %d", 1, n - 1);
			for (int i = 2; i <= (n - 1) / 2; i++) {
				printf(", %d %d", i, n - i);
			}
		}
		printf("\n");
	}
}