/*
이진트리의 성질을 이용하면, 모든 노드를 한번 순회하면서 풀 수 있었습니다.
우측 노드, 현재 노드, 좌측 노드 순으로 방문하면서 값이 큰 노드를 우선하여 방문해줍니다.
방문 순서에 따라서 노드들의 합을 기억해주고, 해당 값으로 노드를 업데이트 해주면 됩니다. 
*/

class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        convert(root, sum);
        return root;
    }
    
    void convert(TreeNode* node, int& sum) {
        if(!node) return;
        convert(node->right, sum);
        node->val = sum += node->val;
        convert(node->left, sum);
    }
};