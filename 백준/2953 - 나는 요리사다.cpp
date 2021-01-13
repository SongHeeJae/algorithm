#include <iostream>
using namespace std;

int main() {
	int maxIndex = -1, maxValue = -1;
	int a;
	for (int i = 0; i < 5; i++) {
		int sum = 0;
		for (int j = 0; j < 4 && scanf("%d", &a); j++)
			sum += a;
		if (sum > maxValue) {
			maxValue = sum;
			maxIndex = i + 1;
		}
	}

	printf("%d %d\n", maxIndex, maxValue);

}