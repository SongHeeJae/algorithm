/*
트리를 후위 순회하면서, 방문했던 좌측 노드와 우측 노드를 스왑해주었습니다.
전위 순회하여도 동일한 결과를 얻을 수 있습니다.
*/

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        invertTree(root->left);
        invertTree(root->right);
        swap(root->left, root->right);
        return root;
    }
private:
    void swap(TreeNode*& a, TreeNode*& b) {
        TreeNode* temp = a;
        a = b;
        b = temp;
    }
};
