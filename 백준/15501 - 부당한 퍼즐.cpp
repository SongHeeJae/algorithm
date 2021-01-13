#include <cstdio>
int n, m, a[1000000], s, dir, f = 1;
int startIndex(int mm) {
	for (int i = 0; i < n; i++)
		if (a[i] == mm) return i;
	return -1;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n && scanf("%d", &a[i]); i++);
	for (int i = 0; i < n && scanf("%d", &m); i++) {
		if (i > 1) {
			s = dir ? (s + 1) % n : (s - 1 + n) % n;
			if (m != a[s]) {
				f = 0;
				break;
			}
		}
		else if (i == 0) s = startIndex(m); // 시작위치
		else { // i==1 방향잡기
			int leftVal = s == 0 ? a[n - 1] : a[s - 1];
			dir = leftVal == m ? 0 : 1;
			s = dir ? (s + 1) % n : (s - 1 + n) % n;
		}
	}
	printf("%s puzzle", f ? "good" : "bad");
}

/*
시작 위치와 방향을 잡은 뒤, 그 방향대로 쭉 가면 "good puzzle"이었습니다.
*/