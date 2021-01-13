#include <cstdio>
int main() {
	int n, a[2] = { 0, }, x;
	scanf("%d", &n);
	while (n-- && scanf("%d", &x)) a[x]++;
	printf("%s", a[0] > a[1] ? "Junhee is not cute!" : "Junhee is cute!");
}