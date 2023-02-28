/*
트리를 후위순회하면서, 탐색되는 서브 트리의 노드 구조를 문자열 형태로 map에 저장해줍니다.
map에 현재 탐색하는 서브 트리의 노드 구조가 모두 저장되므로, 중복된 서브 트리인지 즉시 판별해낼 수 있습니다.
*/

class Solution {
public:
    unordered_map<string, int> dup;
    vector<TreeNode*> res;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        postorder(root);
        return res;
    }
private:
    string postorder(TreeNode* node) {
        if(!node) return "";

        string left = postorder(node->left);
        string right = postorder(node->right);
        
        string val = to_string(node->val) + ":" + left + ":" + right;

        if(dup[val]++ == 1) {
            res.push_back(node);
        }
        return val;
    }
};
