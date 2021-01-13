#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, a;
	scanf("%d", &n);
	int p[1001][3];
	for (int i = 0; i < n; i++)
		scanf("%d %d %d", &p[i][0], &p[i][1], &p[i][2]);
	int d[1001][3] = { p[0][0], p[0][1], p[0][2] };
	for (int i = 1; i < n; i++) {
		d[i][0] = min(d[i - 1][1], d[i - 1][2]) + p[i][0];
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + p[i][1];
		d[i][2] = min(d[i - 1][0], d[i - 1][1]) + p[i][2];
	}


	printf("%d\n",min(min(d[n-1][0], d[n-1][1]), d[n-1][2]));
}