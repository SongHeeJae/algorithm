#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n[3];
	scanf("%d %d %d", &n[0], &n[1], &n[2]);
	sort(n, n + 3);
	int a = n[2] - n[1];
	int b = n[1] - n[0];
	if (a == b) {
		if (n[0] - a >= -100) printf("%d\n", n[0] - a);
		else printf("%d\n", n[2] + a);
	}
	else {
		int d = a > b ? b : a;
		if (n[0] + d != n[1]) printf("%d\n", n[0] + d);
		else if (n[1] + d != n[2]) printf("%d\n", n[1] + d);
	}
}