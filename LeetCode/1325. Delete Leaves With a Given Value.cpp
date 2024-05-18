/*
재귀적으로 풀 수 있었습니다.
각 노드가 leaf node이고 val == target이라면 NULL을 반환하고, 상위 노드는 해당 값으로 업데이트합니다.
*/

class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(!root) return NULL;
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);
        if(!root->left && !root->right && root->val == target) {
            return NULL;
        }
        return root;
    }
};
