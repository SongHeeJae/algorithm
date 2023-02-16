/*
DFS로 모든 노드를 탐색하며 가장 깊은 depth를 찾아줍니다.
*/

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
