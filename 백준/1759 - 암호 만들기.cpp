#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 16

int l, c;
char ch[MAX], res[MAX];

bool isMo(char alp) {
	return alp == 'a' || alp == 'e' || alp == 'i' || alp == 'o' || alp == 'u';
}

bool isJa(char alp) {
	return !isMo(alp);
}

void f(int idx, int mo, int ja, int len) {
	if (idx == c + 1) return;
	if (len == l) {
		if (mo > 0 && ja > 1) {
			cout << res << "\n";
		}
		return;
	}

	res[len] = ch[idx];
	f(idx + 1, mo + isMo(ch[idx]), ja + isJa(ch[idx]), len + 1);
	f(idx + 1, mo, ja, len);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		cin >> ch[i];
	}
	sort(ch, ch + c);
	f(0, 0, 0, 0);
 }

 /*
 주어진 문자를 정렬하고, 재귀로 가능성 있는 암호문을 구해주었습니다.

 --- 기존 코드 ---

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
 */