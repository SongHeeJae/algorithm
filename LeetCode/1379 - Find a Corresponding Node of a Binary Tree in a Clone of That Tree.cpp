/*
모든 노드를 방문하면서 target을 찾아주면 됩니다.
주소값을 이용하면 값이 고유하지 않아도 찾아낼 수 있습니다.
*/

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(!original) return NULL;
        if(target == original) return cloned;
        if(TreeNode* left = getTargetCopy(original->left, cloned->left, target)) return left; 
        return getTargetCopy(original->right, cloned->right, target);
    }
};