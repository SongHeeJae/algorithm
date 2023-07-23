/*
노드의 개수가 n인 full binary tree를 구해야합니다.
재귀적으로 좌우측 서브트리를 찾아나가면서, 이미 구해진 n에 대한 full binary tree는 기억해줍니다.
*/

class Solution {
public:
    unordered_map<int, vector<TreeNode*>> dp;
    vector<TreeNode*> allPossibleFBT(int n) {
        if(dp.find(n) != dp.end()) return dp[n];

        if(n == 1) {
            dp[n].push_back(new TreeNode(0));
            return dp[n];
        }

        for(int i=1; i<n; i+=2)
            for(TreeNode* ln : allPossibleFBT(i))
                for(TreeNode* rn : allPossibleFBT(n - i - 1))
                    dp[n].push_back(new TreeNode(0, ln, rn));
        
        return dp[n];
    }
};
