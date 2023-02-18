/*
트리를 중위 순회하면, 오름차순으로 모든 노드를 방문할 수 있습니다.
현재 방문하는 노드와 이전 방문하는 노드를 이용하여 값 차이의 최솟값을 구해주었습니다.
*/

class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        int res = INT_MAX, prv = root->left ? root->left->val - root->val : root->val - root->right->val;
        inorder(root, res, prv);
        return res;
    }
    
private:
    void inorder(TreeNode* node, int& res, int &prv) {
        if(!node) return;
        inorder(node->left, res, prv);
        res = min(res, node->val - prv);
        prv = node->val;
        inorder(node->right, res, prv);
    }
};
