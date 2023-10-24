/*
BFS로 각 row마다 검사하며 최댓값을 찾아주었습니다.
*/

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        pushIfNotNull(q, root);
        while(!q.empty()) {
            int mx = q.front()->val;
            int sz = q.size();
            while(sz--) {
                TreeNode* node = q.front();
                q.pop();

                mx = max(mx, node->val);
                
                pushIfNotNull(q, node->left);
                pushIfNotNull(q, node->right);
            }
            res.push_back(mx);
        }

        return res;
    }

private:
    void pushIfNotNull(queue<TreeNode*>& q, TreeNode* node) {
        if(node) q.push(node);
    }
};

/*
DFS를 이용한 풀이도 가능했습니다.
각 노드를 방문할 때마다, 속한 row의 최댓값을 업데이트해줍니다.
*/

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        dfs(root, 0, res);
        return res;
    }

private:
    void dfs(TreeNode* node, int row, vector<int>& res) {
        if(!node) return;
        
        if(row >= res.size()) res.push_back(node->val);
        else res[row] = max(res[row], node->val);

        dfs(node->left, row + 1, res);
        dfs(node->right, row + 1, res);
    }
};
