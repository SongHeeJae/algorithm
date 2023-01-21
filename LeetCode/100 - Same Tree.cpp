/*
p와 q를 같은 구조로 탐색해나갑니다.
p 또는 q에서 현재 탐색해야할 노드가 없으면, p와 q 모두 노드가 없어야합니다.
p와 q에서 탐색할 노드가 있으면, 두 값이 같아야합니다.
*/

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p || !q) return !p && !q;
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
