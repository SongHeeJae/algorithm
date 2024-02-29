/*
BFS로 풀 수 있었습니다.
각 depth별로 좌측 노드부터 순차적으로 순회하며, 조건에 맞는지 확인해줍니다. 
*/

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        bool asc = true;
        while(!q.empty()) {
            int sz = q.size();
            int cur = asc ? INT_MIN : INT_MAX;
            while(sz--) {
                TreeNode* node = q.front();
                q.pop();

                if(asc) {
                    if(!(node->val % 2) || node->val <= cur) return false;
                } else {
                    if(node->val % 2 || node->val >= cur) return false;
                }

                cur = node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            asc = !asc;
        }

        return true;
    }
};
