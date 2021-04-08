#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define INF 2147483647
#define MOD 1000000007
using namespace std;

vector<long long int> tree;
long long int arr[1000000];
int n, m, k, a, b, c;

long long int init(int left, int right, int node) {
	if (left == right) return tree[node] = arr[left];
	int mid = (left + right) / 2;
	return tree[node] = init(left, mid, node * 2 + 1) * init(mid + 1, right, node * 2 + 2) % MOD;
}

long long int update(int left, int right, int node, int idx, int val) {
	if (idx < left || idx > right) return tree[node];
	if (left == right) return tree[node] = val;
	int mid = (left + right) / 2;
	return tree[node] = update(left, mid, node * 2 + 1, idx, val)
		* update(mid + 1, right, node * 2 + 2, idx, val) % MOD;
}

long long int getValue(int left, int right, int start, int end, int node) {
	if (left > end || right < start) return 1;
	if (start <= left && right <= end) return tree[node];
	int mid = (left + right) / 2;
	return getValue(left, mid, start, end, node * 2 + 1) * getValue(mid + 1, right, start, end, node * 2 + 2) % MOD;
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	int h = log2(n) + 0.99999;
	int size = (1 << (h + 1)) - 1;
	tree.resize(size, 1);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	init(0, n - 1, 0);
	for (int i = 0; i < k + m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if (a == 1)update(0, n - 1, 0, b - 1, c);
		else printf("%lld\n", getValue(0, n - 1, b-1, c-1, 0));
	}
}

/*
세그먼트 트리를 이용해서 구간 곱을 기억해두었습니다.
*/