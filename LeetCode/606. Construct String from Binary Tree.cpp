/*
전위순회하며 재귀적으로 풀 수 있었습니다.
좌측 노드가 없더라도 우측 노드가 있으면 빈 괄호를 넣어줍니다.
*/

class Solution {
public:
    string tree2str(TreeNode* root) {
        string str = to_string(root->val);
        if(root->left) {
            str += "(" + tree2str(root->left) + ")";
        } else {
            if(root->right) {
                str += "()";
            }
        }
        if(root->right) {
            str += "(" + tree2str(root->right) + ")";
        }
        return str;
    }
};
