/*
간단한 dp 문제였습니다.
dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3]
*/

class Solution {
public:
    int dp[38] = {0, 1, 1};
    int tribonacci(int n) {
        for(int i=3; i<=n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
        return dp[n];
    }
};
