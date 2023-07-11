/*
BFS로 target을 찾을 때 까지, 각 노드의 상위 노드를 저장해줍니다.
target을 찾았으면, 각 노드의 상/하위 노드를 이용하여 k 거리를 가지는 노드로 이동할 수 있습니다.
target부터 다시 BFS를 수행하면서, k 거리에 있는 노드들을 찾아줍니다.
*/

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent = initParentNodesUntilTargetIsFound(root, target);
        return findDistanceNodes(target, k, parent);
    }

    unordered_map<TreeNode*, TreeNode*> initParentNodesUntilTargetIsFound(TreeNode* root, TreeNode* target) {
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if(node == target) return parent;
            push(q, node->left, node, parent);
            push(q, node->right, node, parent);
        }
        return parent;
    }

    void push(queue<TreeNode*>& q, TreeNode* node, TreeNode* p, unordered_map<TreeNode*, TreeNode*>& parent) {
        if(node) {
            q.push(node);
            parent[node] = p;
        }
    }

    vector<int> findDistanceNodes(TreeNode* target, int dist, unordered_map<TreeNode*, TreeNode*>& parent) {
        unordered_set<int> visit;
        queue<TreeNode*> q;
        q.push(target);
        visit.insert(target->val);

        while(!q.empty() && dist--) {
            int sz = q.size();
            while(sz--) {
                TreeNode* node = q.front(); q.pop();
                push(q, node->left, visit);
                push(q, node->right, visit);
                push(q, parent[node], visit);
            }
        }

        vector<int> res;
        while(!q.empty())
            res.push_back(q.front()->val), q.pop();
        return res;
    }

    void push(queue<TreeNode*>& q, TreeNode* node, unordered_set<int>& visit) {
        if(node && visit.find(node->val) == visit.end()) {
            q.push(node);
            visit.insert(node->val);
        }
    }
};
