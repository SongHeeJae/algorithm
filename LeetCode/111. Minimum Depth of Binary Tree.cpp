/*
BFS로 한 depth씩 탐색하며, 리프 노드를 만났을 때의 depth를 반환해줍니다.
*/

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;

        int depth = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            depth++;
            int sz = q.size();
            while(sz--) {
                TreeNode* node = q.front(); q.pop();
                int curSize = q.size();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                if(curSize == q.size()) return depth;
            }
        }
        return depth;
    }
};
