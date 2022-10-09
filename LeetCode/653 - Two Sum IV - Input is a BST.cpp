/*
모든 노드를 순회하면서 방문하는 수를 저장해줍니다.
(k - 현재 노드의 값)이 저장되어 있다면, 두 수의 합으로 k를 만들 수 있음을 의미합니다.
*/

class Solution {
public:
    set<int> values;
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        if(values.find(k - root->val) != values.end()) return true;
        values.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};
