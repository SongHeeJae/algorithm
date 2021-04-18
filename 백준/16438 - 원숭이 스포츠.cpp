#include <cstdio>
int arr[7][99], n;
void dfs(int l, int r, int day, int team) {
	if (day == 7) return;
	int mid = (l + r) / 2;
	for (int i = l; i <= r; i++)
		arr[day][i] = i <= mid ? team : !team;
	dfs(l, mid, day + 1, !team);
	dfs(mid + 1, r, day + 1, team);
}
int main() {
	scanf("%d", &n);
	dfs(0, n - 1, 0, 0);
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < n; j++)
			printf("%c", arr[i][j] ? 'A' : 'B');
		printf("\n");
	}
}

/*
팀을 각 범위마다 절반씩 섞어주었습니다.
*/