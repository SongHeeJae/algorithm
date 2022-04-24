/*
노드를 순회하면서 가장 작은 노드부터 방문해주었습니다. 
*/

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        return inorder(root, k);
    }
    
    int inorder(TreeNode* node, int& k) {
        if(!node) return 0;
        if(int ret = inorder(node->left, k)) return ret;
        return --k ? inorder(node->right, k) : node->val;
    }
};

/*
- Follow up
코드를 작성하진 않고 생각만 해봤습니다.
k번째 작은 노드의 값과 포인터를 기억해주는 것입니다.
삽입되는 값이 현재 노드보다 크다면 그대로 두고,
삽입되는 값이 현재 노드보다 작다면, 삽입 후에 더 작은 값(왼쪽 자식 노드 이용)으로 업데이트해줍니다.
삭제되는 값이 현재 노드보다 크다면 그대로 두고,
삭제되는 값이 현재 노드보다 작다면, 삭제 전에 더 큰 값(부모 또는 우측 자식 노드 이용)으로 업데이트해줍니다.
*/