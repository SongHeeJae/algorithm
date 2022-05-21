/*
dfs를 이용하여 풀 수 있었습니다.
새로운 최대 깊이의 노드를 방문할 때마다 sum을 초기화해주거나, 기존 최대 깊이의 노드를 방문하면 sum에 더해줍니다.
*/

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0, mDepth = 0;
        dfs(root, 0, mDepth, sum);
        return sum;
    }
    
    void dfs(TreeNode* node, int depth, int& mDepth, int& sum) {
        if(!node) return;
        
        if(depth == mDepth) {
            sum += node->val;
        } else if(depth > mDepth) {
            mDepth = depth;
            sum = node->val;
        }
        
        dfs(node->left, depth + 1, mDepth, sum);
        dfs(node->right, depth + 1, mDepth, sum);
    }
};

/*
bfs를 이용하여 풀 수도 있었습니다.
각 깊이마다 노드들의 합을 구해주면서 마지막 합을 반환해줍니다.
*/
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int sum;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            sum = 0;
            for(int i=q.size();i--;q.pop()) {
                TreeNode* node = q.front();
                sum += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return sum;
    }
};