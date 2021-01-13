#include <iostream>
#include <algorithm>
using namespace std;
int n;
int num[101], ans[101];
int c = 0;

bool visited[101] = { false, };
bool visited2[101] = { false, };

void dfs(int a) {
	visited[a] = true;
	if (!visited[num[a]]) dfs(num[a]);
	else {
		if (!visited2[num[a]]) {
			for (int i = num[a]; i != a; i = num[i])
				ans[c++] = i;
			ans[c++]=a;
		}
	}
	visited2[a] = true;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &num[i]);
	for (int i = 1; i <= n; i++)
		if(!visited[i]) dfs(i);
	sort(ans, ans + c);
	printf("%d\n", c);
	for (int i = 0; i < c; i++)printf("%d\n", ans[i]);
}