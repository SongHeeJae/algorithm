#include <iostream>
using namespace std;

int main() {
	int n, c = 1, a=1;
	scanf("%d", &n);
	for (int a = 1; a < n; a += c * 6, c++);
	printf("%d\n", c);

}