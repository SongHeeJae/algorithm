/*
i번 문제를 풀지 않는 경우, dp[i] = dp[i + 1]
i번 문제를 푸는 경우, dp[q[i][1] + i + 1] + q[i][0]
두 경우 중 포인트가 더 커지는 상황을 선택하면 됩니다.
*/

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
