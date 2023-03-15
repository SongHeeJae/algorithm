/*
BFS로 풀 수 있었습니다.
마지막 depth에 도달했음을 알리는 플래그를 선언해줍니다.
노드의 자식 노드를 큐에 넣으며 탐색하다가, 큐에 담긴 노드가 NULL이라면, 어떠한 경로에서는 마지막 depth에 도달했음을 의미합니다.
complete binary tree이기 때문에, 어떠한 경로에서 이미 마지막 depth에 도달하였다면, 새롭게 큐에 넣을 수 있는 노드는 없어야합니다.
*/

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool last = false;

        while(!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if(!node) {
                last = true;
                continue;
            }

            if(last) return false;

            q.push(node->left);
            q.push(node->right);
        }
        return true;
    }
};
