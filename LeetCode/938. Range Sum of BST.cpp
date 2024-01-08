/*
트리를 재귀적으로 순회하면서 범위 내의 합을 구해줍니다.
현재 노드의 값이 low 보다 작다면, 노드의 우측 하위 노드만 탐색해줍니다.
현재 노드의 값이 high 보다 크다면, 노드의 좌측 하위 노드만 탐색해줍니다.
*/

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;
        if(root->val < low) return rangeSumBST(root->right, low, high);
        if(root->val > high) return rangeSumBST(root->left, low, high);
        return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
};
