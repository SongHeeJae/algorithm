#include <cstdio>
int t, x1, y1, x2, y2, cx, cy, r, n, c;
int getVal(int xx, int yy) {
	return (cx - xx) * (cx - xx) + (cy - yy) * (cy - yy);
}
int main() {
	scanf("%d", &t);
	while (t--) {
		c = 0;
		scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &n);
		while (n--) {
			scanf("%d %d %d", &cx, &cy, &r);
			c += (getVal(x1, y1) <= r * r) ^ (getVal(x2, y2) <= r * r);
		}
		printf("%d\n", c);
	}
}

/*
출발점과 도착점 중에서 하나의 점만 각 원 안에 포함될 때 횟수를 증가시켜주었습니다.
포함 여부는 점 사이의 거리와 원의 반지름으로 구해주었습니다.
*/