#include <cstdio>

int n, s[20], cnt[2000001] = { 0 }, ans = 1;

void dfs(int sum, int depth) {
	if (depth == n) {
		cnt[sum] = 1;
		return;
	}
	dfs(sum, depth + 1);
	dfs(sum + s[depth], depth + 1);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &s[i]);
	dfs(0, 0);
	while (cnt[ans++]);
	printf("%d", ans - 1);
}

/*
나올 수 있는 모든 부분 수열의 합을 체크해준 뒤, 가장 작은 값을 구해주었습니다.
*/