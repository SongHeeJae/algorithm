/*
각 횟수에서의 sum을 저장해줍니다.
dp[n][target] = dp[n-1][target - (1...k)]
*/

class Solution {
public:
    int dp[31][1001];

    int numRollsToTarget(int n, int k, int target) {
        memset(dp, -1, sizeof(dp));
        return f(n, k, target);
    }

    int f(int n, int k, int target) {
        if(n == 0) {
            return target == 0;
        }

        if(target < 0) return 0;

        int& c = dp[n][target];
        if (c != -1) return c;

        c = 0;
        for(int i=1; i<=k; i++) {
            c += f(n - 1, k, target - i);
            c %= 1000000007;
        }
        return c;
    }
};
