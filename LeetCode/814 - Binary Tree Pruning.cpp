/*
트리를 후위 순회하면서, 서브트리의 모든 노드가 0인 경우 제거해주었습니다.
*/

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(!root) return NULL;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        return root->val || root->left || root->right ? root : NULL;
    }
};
