#include <iostream>
using namespace std;
#define MAX 1000

int t, n;
int pre[MAX], in[MAX];
int nodeIdxInInorder[MAX];

void postorder(int rootIdxInPreorder, int left, int right) {
	if (left > right) return;

	int root = pre[rootIdxInPreorder];
	int rootIdxInInorder = nodeIdxInInorder[root];
	int leftSubTreeSize = rootIdxInInorder - left;

	int leftSubTreeRootIdxInPreorder = rootIdxInPreorder + 1;
	int rightSubTreeRootIdxInPreorder = leftSubTreeRootIdxInPreorder + leftSubTreeSize;
	postorder(leftSubTreeRootIdxInPreorder, left, rootIdxInInorder - 1);
	postorder(rightSubTreeRootIdxInPreorder, rootIdxInInorder + 1, right);
	cout << root << " ";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> pre[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> in[i];
		}
		for (int i = 0; i < n; i++) {
			nodeIdxInInorder[in[i]] = i;
		}
		postorder(0, 0, n - 1);
		cout << "\n";
	}
}

/*
preorder 리스트의 첫 번째 방문하는 노드는 트리의 루트가 됩니다.
inorder 리스트에서 루트 노드를 기준으로, 좌측 서브트리와 우측 서브트리의 노드를 구할 수 있습니다.
좌측 서브트리의 루트 노드는, preorder 리스트에서 현재 루트 노드 다음으로 방문하는 노드입니다.
우측 서브트리의 루트 노드는, preorder 리스트에서 지금 구한 좌측 서브 트리를 모두 방문한 다음에 방문하는 노드입니다.
preorder에서 구한 각 루트 노드의 inorder 리스트 인덱스 번호를 빠르게 구하기 위해, 
노드가 방문하는 inorder 순서 인덱스를 전처리해두었습니다.
*/