#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
	char c;
	int count = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			c = getchar();
			if ((i + j) % 2 == 0 && c == 'F') count++;
		}
		getchar();
	}
	printf("%d\n", count);
}