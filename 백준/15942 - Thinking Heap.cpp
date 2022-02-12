#include <iostream>
#include <algorithm>
#include <cmath>
#define MAX 200000
using namespace std;

int n, k, p, heap[MAX + 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k >> p;

	int pHeight = log2(p) + 1;
	if (pHeight > k) {
		cout << -1;
		return 0;
	}

	int mHeight = log2(n) + 1;
	int diffHeight = mHeight - pHeight;
	int leafTotalCntWhenRootP = 1 << diffHeight;
	int rightLeafIdxWhenRootP = p * (1 << diffHeight) + (1 << diffHeight) - 1;
	int leafCntWhenRootP = max(0, n >= rightLeafIdxWhenRootP ? leafTotalCntWhenRootP : leafTotalCntWhenRootP - (rightLeafIdxWhenRootP - n));
	int cntWhenRootP = (1 << diffHeight) - 1 + leafCntWhenRootP;
	int possibleLastIdx = k + cntWhenRootP - 1;
	if (possibleLastIdx > n) {
		cout << -1;
		return 0;
	}

	for (int v = pHeight, prt = p >> 1; v--; prt >>= 1)
		heap[prt] = v;

	heap[p] = MAX;
	int s = n - cntWhenRootP + 2;
	int v1 = pHeight + (pHeight == k);
	int v2 = s;
	for (int i = 1; i <= n; i++) {
		if (heap[i]) continue;
		if (heap[i >> 1] >= s) heap[i] = v2++;
		else {
			heap[i] = v1++;
			if (v1 == k) v1++;
		}
	}
	heap[p] = k;

	for (int i = 1; i <= n; i++)
		cout << heap[i] << '\n';
}

/*
노드가 삽입될 때, 부모 노드보다 값이 크면 움직일 필요가 없다는 점을 이용하였습니다.
p에 k가 삽입되면,
루트부터 p의 부모까지는 1부터 커지는 값을 지정해주고,
리프노드부터 p의 자식까지는 n부터 작아지는 값을 지정해줍니다.
p의 모든 노드와 자식들은 최소 힙을 만족하므로, 비어있는 다른 노드들도 최소 힙을 만족시키도록 지정해주면 됩니다.
아직 사용되지 않은 수들을, 상위 노드부터 비어있는 노드에 순차적으로 커지도록 넣어준다면,
해당 노드의 부모 노드는 더 작은 수를 가지고 있으므로 최소 힙을 유지할 수 있습니다.
결국 완성된 최소 힙은 스왑할 필요가 없었으므로 삽입 순서가 됩니다.

삽입 순서가 존재하지 않는 경우를 찾아줘야했는데,
남은 수들을 이용하여 p의 모든 상위 노드와 하위 노드들을 채울 수 있는지 검사해주면 됩니다.

상위 노드는 간단하게 판별할 수 있습니다.
p의 높이와 k의 값을 이용해서 상위 노드부터 p까지 값을 채울 수 있는지 검사해주면 됩니다.
p의 높이가 k보다 크다면, 상위 노드에 최소 힙을 만족하는 수들로 채워낼 수 없습니다.

하위 노드를 판별한 방식은 다음과 같습니다.
p를 루트로 하는 서브트리의 모든 노드를, n부터 시작했을 때 k 이상의 값으로 다 채울 수 없다면, 하위 노드에 최소 힙을 만족하는 수들로 채워낼 수 없습니다.
모든 노드는 부모 노드보다 커야하기 때문입니다.

이를 위해 서브트리의 모든 노드 개수를 구해야했습니다.
이 값은 서브트리가 포화이진트리일 때의 가장 우측 리프노드 인덱스 번호, 서브트리가 포화이진트리일 때의 리프 노드 개수, n을 이용해서 구할 수 있었습니다.
*/