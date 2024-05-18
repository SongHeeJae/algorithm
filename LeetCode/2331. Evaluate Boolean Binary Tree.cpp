/*
좌우측 하위 노드가 true 또는 false 라면, 노드의 val에 따라 and 또는 or 연산을 수행하여 결과를 반환해줍니다.
*/

class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if(root->val <= 1) return root->val;
        bool left = evaluateTree(root->left);
        bool right = evaluateTree(root->right);
        return root->val == 2 ? left || right : left && right;
    }
};
