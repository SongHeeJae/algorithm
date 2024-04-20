/*
BFS로 (depth - 1)번째 노드를 모두 찾아줍니다.
val 값과 찾은 노드의 좌/우측 서브트리를 가진 노드를 생성해주고, 기존 노드의 좌/우측 서브트리로 연결해줍니다.  
*/

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            return new TreeNode(val, root, NULL);
        }

        queue<TreeNode*> q;
        q.push(root);

        for(int i=2; i<depth; i++) {
            int sz = q.size();
            while(sz--) {
                TreeNode* node = q.front(); q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }

        while(!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            node->left = new TreeNode(val, node->left, NULL);
            node->right = new TreeNode(val, NULL, node->right);
        }
        return root;
    }
};
