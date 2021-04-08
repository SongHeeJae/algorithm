#include <iostream>
#include <vector>
#include <cmath>
#define SIZE 2000000
using namespace std;
vector<int> tree;
int n, t, x;
int update(int left, int right, int node, int idx, int val) {
	if (idx < left || idx > right) return tree[node];
	if (left == right) return tree[node] += val;
	int mid = (left + right) / 2;
	return tree[node] = update(left, mid, node * 2, idx, val)
		+ update(mid + 1, right, node * 2 + 1, idx, val);
}

int query(int left, int right, int node, int k) {
	if (left == right) {
		tree[node]--;
		return left;
	}
	int mid = (left + right) / 2, ret;
	if (k <= tree[node * 2]) ret = query(left, mid, node * 2, k);
	else ret = query(mid + 1, right, node * 2 + 1, k - tree[node * 2]);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
	return ret;
}

int main() {
	int h = log2(SIZE + 1) + 0.99999;
	int size = (1 << (h + 1));
	tree.resize(size, 0);
	scanf("%d", &n);
	while (n--) {
		scanf("%d %d", &t, &x);
		if (t == 1) update(1, SIZE, 1, x, 1);
		else printf("%d\n", query(1, SIZE, 1, x));
	}
}

/*
세그먼트 트리를 이용해서 K번째 수를 찾아줬습니다.
먼저 X의 수 범위 값만큼 담을 수 있는 세그먼트 트리를 0으로 초기화해줍니다.
T가 1이라면, 추가해야 할 X를 인덱스 번호로 생각해서 해당 인덱스 번호의 구간합을 +1 해줍니다.
T가 2라면, K번째 수를 찾아야합니다.
왼쪽 노드의 구간합이 k보다 작거나 같다면, 왼쪽 구간으로 들어가서 k번째를 찾습니다.
왼쪽 노드의 구간합이 k보다 크다면, 오른쪽 구간으로 들어가서 그 구간에서의 새로운 k번째를 찾습니다.
k번째를 찾았으면, 구간합을 -1 해준 뒤 값을 반환하며 업데이트해줍니다.
*/