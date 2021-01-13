#include <iostream>
#include <algorithm>
int n, a[10000], v[10000] = { 0 }, b[10000], c[10000], f = 0, f1 = 1;
void fun(int cnt) {
	if (cnt == n) {
		f1 = 0;
		if (f) {
			for (int i = 0; i < n; i++) printf("%d ", c[i]);
			exit(0);
		}
		int i;
		for (i = 0; i < n; i++)
			if (b[i] != c[i]) break;
		if (i == n) f = 1;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (f1 == 1 && a[i] != b[cnt]) continue;
		if (v[i]) continue;
		v[i] = 1;
		c[cnt] = a[i];
		fun(cnt + 1);
		v[i] = 0;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) a[i] = i + 1;
	for (int i = 0; i < n; i++) scanf("%d", &b[i]);
	fun(0);
	printf("-1");
}

/*
현재 재귀의 깊이에서 나와야하는 수(입력한 수)가 아니라면 모두 continue 시켜줬습니다.

그러다가 입력한 수가 한 번 나오면, 그때 플래그 변수로 더이상 continue 시키지않게 바꿔줬습니다.

그 다음으로 다시 cnt == n을 충족했을 때가 다음 순열입니다.

*/