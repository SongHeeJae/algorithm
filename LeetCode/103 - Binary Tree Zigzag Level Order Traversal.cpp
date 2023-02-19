/*
BFS를 이용하여 풀 수 있었습니다.
한 레벨씩 탐색한 결과를 기억해주고, 역순인 시점에는 탐색 결과를 뒤집어주면 됩니다.
*/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};

        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;
        vector<vector<int>> res;

        while(!q.empty()) {
            int sz = q.size();
            vector<int> temp;

            while(sz--) {
                TreeNode* node = q.front();
                q.pop();
                
                temp.push_back(node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(flag) reverse(temp.begin(), temp.end());
            flag = !flag;
            res.push_back(temp);
        }
        return res;
    }
};
