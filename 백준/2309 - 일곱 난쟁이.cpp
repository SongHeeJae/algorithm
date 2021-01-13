#include <iostream>
#include <algorithm>
using namespace std;
int a[9], b[7];
void dfs(int c, int idx) {
	if (c == 7) {
		int s = 0;
		for (int i = 0; i < 7; i++) s += b[i];
		if (s == 100) {
			for (int i = 0; i < 7; i++) printf("%d\n", b[i]);
			exit(0);
		}
		return;
	}
	for (int i = idx; i < 9; i++) {
		b[c] = a[i];
		dfs(c + 1, i + 1);
	}
}

int main() {
	for (int i = 0; i < 9; i++) scanf("%d", &a[i]);
	sort(a, a + 9);
	dfs(0, 0);
}
