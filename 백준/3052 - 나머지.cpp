#include <iostream>

int main() {
	int rm[42] = { 0, };
	int a, s=0;
	for (int i = 0; i < 10 && scanf("%d", &a); i++) {
		if (rm[a % 42] == 0) s++;
		rm[a % 42]++;
	}
	printf("%d\n", s);
}