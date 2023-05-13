class Solution {
public:
    long long mostPoints(vector<vector<int>>& q) {
        long long dp[100001] = {0};
        int n = q.size();
        for(int i = n - 1; i>=0; i--) {
            dp[i] = max(dp[i + 1], q[i][0] + dp[min(q[i][1] + i + 1, n)]);
        }
        return dp[0];
    }
};
