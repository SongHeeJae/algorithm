#include <cstdio>

int n, m, ans = 0;
char a[50][51], b[50][51];

void input(char c[][51]) {
	for (int i = 0; i < n; i++)
		scanf("%s", c[i]);
}

void reverse(int x, int y) {
	for (int i = x; i < x + 3; i++)
		for (int j = y; j < y + 3; j++)
			a[i][j] = a[i][j] == '1' ? '0' : '1';
}

int isEquals() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] != b[i][j]) return -1;
	return ans;
}

int main() {
	scanf("%d %d", &n, &m);
	input(a);
	input(b);
	for (int i = 0; i < n - 2; i++)
		for (int j = 0; j < m - 2; j++)
			if (a[i][j] != b[i][j])
				reverse(i, j), ans++;
	printf("%d", isEquals());
} 

/*
왼쪽 위에서부터 서로 값이 다르다면 뒤집는 연산을 수행해주었습니다.
*/