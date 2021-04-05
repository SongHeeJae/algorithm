#include <iostream>
#include <queue>
using namespace std;
queue<int> q;
int n, k, c = 0, ans[5000], cnt = 0;
int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n ; i++)q.push(i);
	while (!q.empty()) {
		if (++c == k) c = 0, ans[cnt++] = q.front();
		else q.push(q.front());
		q.pop();
	}
	printf("<%d", ans[0]);
	for (int i = 1; i < cnt; i++) printf(", %d", ans[i]);
	printf(">");
}