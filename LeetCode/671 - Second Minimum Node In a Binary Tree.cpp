/*
root의 모든 자식 노드는, root->val 보다 클 수 없습니다.
즉, root->val이 firstMinimumValue입니다.
root->val 보다 크면서, 다른 모든 노드보다 작은 값이 secondMinimumValue가 됩니다.
트리의 모든 노드를 순회하면서, root->val이 아니면서 가장 작은 값을 찾아주면 됩니다.
val의 범위보다 큰 값으로 결과를 초기화하고, 모든 트리를 순회해주면 될 것입니다.
하지만 val의 범위는 1 ~ (2^31-1)이기 때문에, int형 범위 최솟값인 2^31을 기준으로 잡고, 음의 부호를 붙였을 때의 최댓값을 찾아주었습니다.
*/

class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        int res = INT_MIN;
        dfs(root, res, root->val);
        return res == INT_MIN ? -1 : -res;
    }

    void dfs(TreeNode* node, int& res, int rootVal) {
        if(!node) return;
        if(node->val != rootVal) res = max(res, -node->val);
        dfs(node->left, res, rootVal);
        dfs(node->right, res, rootVal);
    }
};
 
