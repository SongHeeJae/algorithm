#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define INF 2147483647
using namespace std;

int n, m, a, b;
vector<pair<int, int>> tree;
vector<int> arr;

pair<int, int> init(int left, int right, int node) {
	if (left == right) return tree[node] = {arr[left], arr[left]};
	int mid = (left + right) / 2;
	pair<int, int> ret1 = init(left, mid, node * 2 + 1);
	pair<int, int> ret2 = init(mid + 1, right, node * 2 + 2);
	tree[node].first = max(ret1.first, ret2.first);
	tree[node].second = min(ret1.second, ret2.second);
	return tree[node];
}

pair<int, int> getValue(int left, int right, int a, int b, int node) {
	if (left > b || right < a) return { 0, INF };
	if (a <= left && right <= b) return tree[node];
	int mid = (left + right) / 2;
	pair<int, int> ret1 = getValue(left, mid, a, b, node * 2 + 1);
	pair<int, int> ret2 = getValue(mid + 1, right, a, b, node * 2 + 2);
	return { max(ret1.first, ret2.first), min(ret1.second, ret2.second) };
}

int main() {
	scanf("%d %d", &n, &m);
	int h = log2(n) + 0.9999;
	int size = (1 << (h + 1)) - 1;
	tree.resize(size, {0, INF});
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		arr.push_back(a);
	}
	init(0, n - 1, 0);
	while (m--) {
		scanf("%d %d", &a, &b);
		pair<int, int> res = getValue(0, n - 1, a - 1, b - 1, 0);
		printf("%d %d\n", res.second, res.first);
	}
}