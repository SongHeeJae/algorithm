#include <iostream>
#include <vector>
using namespace std;

void preorder(vector<int>& in, vector<int>& post, int si, int ei, int sp, int ep) {
	if (si > ei || sp > ep) return;

	printf("%d ", post[ep]); // postorder 제일 끝값이 루트
	int i = in[post[ep] - 1]; // 지금 루트 값이 담긴 위치. 양옆은 left, right 노드
	int left = i - si;
	preorder(in, post, si, i - 1, sp, sp + left - 1); // 분할
	preorder(in, post, i + 1, ei, sp + left, ep - 1);

}

int main()
{
	int n, a;
	scanf("%d", &n);
	vector<int> in(n);
	vector<int> post(n);

	// inorder의 양옆은 자식노드
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		in[a - 1] = i;
	}

	// postorder의 마지막은 루트노드
	for (int i = 0; i < n; i++)
		cin >> post[i];

	preorder(in, post, 0, n-1, 0, n-1);
}