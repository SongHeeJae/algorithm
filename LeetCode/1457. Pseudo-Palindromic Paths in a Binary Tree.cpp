/*
각 노드를 dfs로 순회하며 현재까지 나온 수의 개수를 구해줍니다.
leaf node에 도달하면, 각 수의 홀수가 최대 1번까지만 나오는지 확인해줍니다.
수의 개수가 홀수인게 1개 이하라면, palindrome을 만들 수 있습니다.
*/

class Solution {
public:
    int cnt[10] = {0};
    int pseudoPalindromicPaths (TreeNode* root) {
        if(!root) return 0;
        
        cnt[root->val]++;
        int res = pseudoPalindromicPaths(root->left) + pseudoPalindromicPaths(root->right) + chk(root);
        cnt[root->val]--;
        return res;
    }

private:
    bool chk(TreeNode* node) {
        if(node->left || node->right) return false;

        bool flag = false;
        for(int i=1; i<10; i++) {
            if(cnt[i] % 2) {
                if(flag) return false;
                flag = true;
            }
        }
        return true;
    }
};
