/*
O(h)의 공간복잡도와 O(1)의 시간복잡도라는 조건이 있었습니다.
스택을 이용하여 중위순회하면서 O(h)의 공간을 만족시킬 수 있었습니다.
최악의 경우(우측 노드의 좌측 노드가 늘어진 것처럼)로 계산하면 O(1)이라는 시간복잡도를 계산할 수 없지만, Amortized O(1)은 만족시키는 것으로 보입니다.
*/

class BSTIterator {
public:
    stack<TreeNode*> stk;
    
    BSTIterator(TreeNode* root) {
        for(TreeNode* cur = root; cur != NULL; cur = cur->left)
            stk.push(cur);
    }
    
    int next() {
        TreeNode* top = stk.top();
        stk.pop();
        for(TreeNode* cur = top->right; cur != NULL; cur = cur->left)
            stk.push(cur);
        return top->val;
    }
    
    bool hasNext() {
        return !stk.empty();
    }
};