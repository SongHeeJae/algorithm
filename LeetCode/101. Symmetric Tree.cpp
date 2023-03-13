/*
DFS 재귀 구조로 풀 수 있습니다.
좌측 노드의 우측 자식 노드/우측 노드의 좌측 자식 노드,
좌측 노드의 좌측 자식 노드/우측 노드의 우측 자식 노드가 동일한 값을 가지는지, 재귀적으로 확인해줍니다.
*/

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root->left, root->right);
    }

    bool isSymmetric(TreeNode* left, TreeNode* right) {
        if(left == NULL && right == NULL) return true;
        if(left == NULL || right == NULL) return false;
        
        return left->val == right->val 
            && isSymmetric(left->right, right->left) 
            && isSymmetric(left->left, right->right);
    }
};


/*
BFS 반복문으로 풀 수도 있습니다.
*/

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while(!q.empty()) {
            TreeNode* n1 = q.front(); q.pop();
            TreeNode* n2 = q.front(); q.pop();

            if(n1 == NULL && n2 == NULL) continue;
            if(n1 == NULL || n2 == NULL || n1->val != n2->val) return false;
            
            q.push(n1->left); q.push(n2->right);
            q.push(n1->right); q.push(n2->left);
        }
        return true;
    }
};
