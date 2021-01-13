#include <cstdio>
bool isDivided(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
	double f1 = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
	double f2 = (x2 - x1) * (y4 - y1) - (y2 - y1) * (x4 - x1);
	return f1 * f2 < 0;
}
int main() {
	double x1, y1, x2, y2, x3, y3, x4, y4;
	scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
	if (isDivided(x1, y1, x2, y2, x3, y3, x4, y4)) printf("1");
	else printf("0");
}

/*
각 점은 가장 자리에만 있고 두 직선이 서로를 양분한다면, 두 직선에는 교점이 생기고 4조각으로 나뉠거라고 생각되었습니다.
*/