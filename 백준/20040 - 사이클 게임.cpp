#include <cstdio>
#include <cstring>
int set[500000], n, m, a, b, ans = 0;
int findParent(int x) {
	if (set[x] != -1) return set[x] = findParent(set[x]);
	else return x;
}
int main() {
	memset(set, -1, sizeof(set));
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m && scanf("%d %d", &a, &b); i++) {
		int pa = findParent(a), pb = findParent(b);
		if (pa == pb) {
			ans = i;
			break;
		}
		set[pa] = pb;
	}
	printf("%d", ans);
}

/*
같은 최상위 부모를 공유하고 있다면, 두 점을 연결하는 순간 사이클이 생기게 됩니다.
*/