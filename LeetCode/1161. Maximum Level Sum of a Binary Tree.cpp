/*
BFS를 이용하여 풀었습니다.
각 level 별 sum을 구하고, 가장 작은 level이면서 가장 큰 sum을 가지는 level을 찾아줍니다.
*/

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int resLevel = 1;
        int resSum = root->val;

        queue<TreeNode*> q;
        q.push(root);

        int level = 1;
        while(!q.empty()) {
            int sz = q.size();
            int sum = 0;
            while(sz--) {
                TreeNode* node = q.front(); q.pop();
                sum += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            
            if(sum > resSum) {
                resLevel = level;
                resSum = sum;
            }
            level++;
        }

        return resLevel;
    }
};


