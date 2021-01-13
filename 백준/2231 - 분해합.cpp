#include <cstdio>


int constructor(int n, int index) {
	
	if (n == index + 1) return 0;

	int temp, sum; 

	temp = sum = index;
	while (temp != 0) {
		sum += temp % 10;
		temp /= 10;
	}
	if (n == sum) return index;
	else return constructor(n, index + 1);

}

int main() {
	int n, c = 0;
	scanf("%d", &n);
	int temp = n;
	for (temp = n; temp != 0; temp /= 10, c++);

	printf("%d\n", constructor(n, n - c*9));
}