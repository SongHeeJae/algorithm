/*
중위순회로 방문하는 수가 오름차순인지 검사하며 검증해주었습니다.

서브 트리의 루트는 부모 노드보다 크거나 작은 수만 포함하기 때문에, 동일한 수는 검증에 실패해야합니다.

문제 조건에서 노드의 값은 int의 모든 범위를 포함하는데, 단순하게 이전에 방문한 수를 long long으로 저장해주었습니다.

크기를 비교하거나 값을 대입할 때마다 캐스팅이 일어나므로, 이를 방지할 방법은 고민이 필요해보입니다.
*/

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        long long prev = LONG_MIN;
        return isValidBST(root, prev);
    }
    
private:
    bool isValidBST(TreeNode* node, long long& prev) {
        if(!node) return true;
        if(!isValidBST(node->left, prev)) return false;
        if(node->val <= prev) return false;
        prev = node->val;
        if(!isValidBST(node->right, prev)) return false;
        return true;
    }
};
