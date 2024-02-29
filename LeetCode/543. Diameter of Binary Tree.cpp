/*
좌측 서브트리와 우측 서브트리의 depth를 구해주면, 현재 노드 기준 지름은 양측 서브트리의 depth 합을 이용하여 구할 수 있습니다.
모든 서브트리에 대해 검사하며, 지름의 최댓값을 찾아줍니다.
*/

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }

    int dfs(TreeNode* node, int& res) {
        if(!node) return 0;
        int d1 = dfs(node->left, res);
        int d2 = dfs(node->right, res);
        res = max(res, d1 + d2);
        return max(d1, d2) + 1;
    }
};
