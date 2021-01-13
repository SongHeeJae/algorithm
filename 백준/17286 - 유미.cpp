#include <cstdio>
#include <cmath>
double a[4][2], v[4] = { 1 }, cx, cy, res = 99, x, y;
void f(int idx, double dist, int c) {
	if (c == 3) {
		if (dist < res) res = dist;
		return;
	}
	for (int i = 1; i < 4; i++) {
		if (!v[i]) {
			v[i] = true;
			x = a[idx][0] - a[i][0];
			y = a[idx][1] - a[i][1];
			f(i, dist + sqrt(x * x + y * y), c + 1);
			v[i] = false;
		}
	}
}
int main() {
	for (int i = 0; i < 4; i++) scanf("%lf %lf", &a[i][0], &a[i][1]);
	f(0, 0, 0);
	printf("%d", int(res));
}