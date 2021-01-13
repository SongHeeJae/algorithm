#include <iostream>
#include <string>
using namespace std;

int main() {
	char c;
	while ((c = getchar()) != '\n') {
		if (c != 'C' && c != 'A'
			&& c != 'M' && c != 'B'
			&& c != 'R' && c != 'I'
			&& c != 'D' && c != 'G'
			&& c != 'E') putchar(c);
	}
}

