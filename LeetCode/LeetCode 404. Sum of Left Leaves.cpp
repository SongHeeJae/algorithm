/*
재귀적으로 트리를 DFS 순회하며, 현재 노드가 리프/좌측 노드인지 확인해주고, 해당하는 노드들의 값을 합산해줍니다.
*/

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root, bool left=false) {
        if(!root) return 0;
        bool isLeaf = root->left == NULL && root->right == NULL;
        return sumOfLeftLeaves(root->left, true) 
            + sumOfLeftLeaves(root->right, false)
            + (isLeaf && left ? root->val : 0);
    }
};
