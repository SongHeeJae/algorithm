#include <iostream>

int main() {
	int max = -1, maxIndex, a;
	for (int i = 0; i < 9 && scanf("%d", &a); i++) {
		if (a > max) {
			max = a;
			maxIndex = i + 1;
		}
	}
	printf("%d\n%d\n", max, maxIndex);
}