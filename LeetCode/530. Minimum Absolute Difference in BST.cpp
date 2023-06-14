/*
inorder로 트리를 탐색하면, 오름차순으로 탐색할 수 있습니다.
이전 노드와 현재 노드의 차이를 구하고, 이에 대한 최솟값을 구해줍니다.
*/

class Solution {
public:
    int prv = -1;
    int res = INT_MAX;
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return res;
    }

    void inorder(TreeNode* node) {
        if(!node) return;
        inorder(node->left);
        if(prv != -1) res = min(res, node->val - prv);
        prv = node->val;
        inorder(node->right);
    }
};
