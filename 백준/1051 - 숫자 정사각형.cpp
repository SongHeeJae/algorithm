#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int rect[50][50];
int ans = 1;

void square(int x, int y) {
	for (int i = 1; x + i < n && y + i < m; i++) {
		if (rect[x + i][y] == rect[x][y + i]
			&& rect[x][y + i] == rect[x + i][y + i]
			&& rect[x][y] == rect[x + i][y]) {
			ans = max(ans, (i + 1) * (i + 1));
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		getchar();
		for (int j = 0; j < m; j++) rect[i][j] = getchar() - '0';
	}
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++) square(i, j);
	printf("%d", ans);
}
