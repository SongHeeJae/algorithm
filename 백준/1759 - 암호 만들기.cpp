#include <iostream>
#include <algorithm>
using namespace std;
int l, c;
char a[15], b[16];
bool visited[26] = { false, };
void dfs(int n, int t) {
	if (t == l) {
		b[l] = '\0';
		int c1 = 0, c2 = 0;
		for (int i = 0; i < 26; i++)
			if (visited[i]) {
				if (i == 0 || i == 4 || i == 8 || i == 14 || i == 20) c1++;
				else c2++;
			}
		if(c1>0 && c2 >1) cout << b << "\n";
		return;
	}
	for (int i = n; i < c; i++) {
		if (!visited[a[i] - 'a']) {
			visited[a[i] - 'a'] = true;
			b[t] = a[i];
			dfs(i, t + 1);
			visited[a[i] - 'a'] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> l >> c;
	for (int i = 0; i < c; i++) cin >> a[i];
	sort(a, a + c);
	dfs(0, 0);
}