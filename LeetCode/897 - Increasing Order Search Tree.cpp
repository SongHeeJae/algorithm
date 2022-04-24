/*
중위 순회로 노드를 방문하면서 재배열된 트리를 만들어주었습니다.
*/

class Solution {
public:
    TreeNode* newRoot = NULL;
    TreeNode* cur = NULL;
    
    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        return newRoot;
    }
    
    void inorder(TreeNode* node) {
        if(!node) return;
        inorder(node->left);
        if(!newRoot) cur = newRoot = node;
        else {
            node->left = NULL;
            cur = cur->right = node;
        }
        inorder(node->right);
    }
};