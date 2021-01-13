#include <iostream>
#include <algorithm>
using namespace std;
int n, m, a, ans, s = 0, ch = 0, f = 0;
bool num[10] = { false, };
void dfs(int c) {
	if (s + 2 == c) {
		f = 1;
		return;
	}
	if (f && s + 1 == c) return;
	if (c > 0 && c >= s-1) ans = min(ans, c + abs(n - ch));
	for (int i = 0; i < 10; i++) {
		if (i == 0 && c == 0) continue;
		if (!num[i]) {
			ch = ch * 10 + i;
			dfs(c + 1);
			ch /= 10;
		}
	}
}
int main() {
	scanf("%d %d", &n, &m);
	while (m-- && scanf("%d", &a)) num[a] = true;
	for (int t = n; t; t /= 10, s++);
	ans = abs(100 - n);
	if (m != 10) {
		if (ans != 0) dfs(0);
		if (!num[0])ans = min(ans, abs(n + 1));
	}
	printf("%d", ans);
}