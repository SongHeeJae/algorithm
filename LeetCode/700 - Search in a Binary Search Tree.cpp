/*
이진 트리에서 노드 찾는 함수를 작성하는 문제였습니다.
재귀를 이용하여 풀었습니다.
*/

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root || root->val == val) return root;
        return val < root->val ? searchBST(root->left, val) : searchBST(root->right, val);
    }
};