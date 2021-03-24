#include <iostream>
int dx[] = { -1,0,1 };
int dy[] = { 1,1, 1 };
char map[10002][502];
int r, c, ans = 0;
bool dfs(int x, int y) {
	if (y == c) return true;
	map[x][y] = 'x';
	for (int i = 0; i < 3; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (map[nx][ny] == '.' && dfs(nx, ny)) return true;
	}
	return false;
}

int main() {
	scanf("%d %d", &r, &c);
	for (int i = 1; i <= r; i++) scanf("%s", &map[i][1]);
	for (int i = 1; i <= r; i++) if (dfs(i, 0)) ans++;
	printf("%d", ans);
}

/*

1. 오른쪽 위 대각선
2. 오른쪽
3. 오른쪽 아래 대각선

위 순서대로 우선순위를 준 뒤, 마지막 열까지 도착할 수 있었다면 파이프를 연결한 것입니다.
첫 번째 열은 위에서부터 아래로 검사하며 마지막 열까지 이동하기 때문에,
겹치는 경로 없이 가장 많은 파이프를 설치하려면 위와 같은 우선순위를 가져야합니다.

*/