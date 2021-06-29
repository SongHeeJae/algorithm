#include <iostream>
#include <algorithm>
#define INF 2147483647
using namespace std;

pair<int, int> tree[10001];
int parent[10001] = { 0 };
int l[10001], r[10001];
int n, a, b, c, idx = 1;

int getParent(int node) {
	if (parent[node] == 0) return node;
	else return getParent(parent[node]);
}

int inorder(int node, int level) {
	if (node == -1) return level - 1;
	int ret = level;
	ret = max(ret, inorder(tree[node].first, level + 1));
	l[level] = min(idx, l[level]);
	r[level] = max(idx++, r[level]);
	ret = max(ret, inorder(tree[node].second, level + 1));
	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d", &a, &b, &c);
		tree[a] = { b, c };
		if (b != -1) parent[b] = a;
		if (c != -1) parent[c] = a;
		l[i] = INF;
		r[i] = 0;
	}
	int root = getParent(1);
	int maxLevel = inorder(root, 1);
	int width = 0, level = 1;
	for (int i = 1; i <= maxLevel; i++) {
		int w = r[i] - l[i];
		if (w > width) {
			width = w;
			level = i;
		}
	}
	printf("%d %d", level, width + 1);
}

/*
먼저, 입력받은 트리의 루트를 구해줍니다.
그 후, 각 노드를 중위순회로 방문하는 순서가 각 노드의 열번호가 됩니다.
이를 통해 열번호의 최저값과 최고값을 기억해준 뒤, 각 레벨 별로 트리의 너비를 구해줍니다.
*/