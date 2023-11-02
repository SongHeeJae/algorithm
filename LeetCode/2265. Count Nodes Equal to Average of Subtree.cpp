/*
트리를 후위순회하면,
각 좌우측 서브트리의 연산 결과(노드의 합과 개수)를 이용하여,
루트 노드의 값과 평균이 일치하는지 확인할 수 있습니다.
*/

class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        int res = 0;
        postorder(root, res);
        return res;
    }

    pair<int, int> postorder(TreeNode* node, int& res) {
        if(!node) return {0, 0};
        pair<int,int> left = postorder(node->left, res);
        pair<int,int> right = postorder(node->right, res);
        
        pair<int,int> ret = {
            left.first + right.first + node->val,
            left.second + right.second + 1
        };
        res += node->val == ret.first / ret.second;
        return ret;
    }
};
