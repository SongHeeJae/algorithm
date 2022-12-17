/*
모든 노드의 합을 구해줍니다.
각 노드를 탐방하며 간선으로 분리된 두 서브트리의 합을 구해줍니다.
이를 이용하여 곱의 최댓값을 구해줍니다.
*/

typedef long long ll;

class Solution {
public:
    int MOD = 1e9 + 7;
    int maxProduct(TreeNode* root) {
        ll res = 0;
        maxProduct(root, getTotal(root), res);
        return res % MOD;
    }
private:
    int maxProduct(TreeNode* root, ll total, ll& res) {
        if(!root) return 0;
        int leftSum = maxProduct(root->left, total, res);
        int rightSum = maxProduct(root->right, total, res);
        res = max({res, leftSum * (total-leftSum), rightSum * (total-rightSum)});
        return leftSum + rightSum + root->val;
    }

    ll getTotal(TreeNode* root) {
        if(!root) return 0;
        return root->val + getTotal(root->left) + getTotal(root->right);
    }
};
