/*
dp[i] = 길이가 i인 문자열 개수를 저장해줍니다.
dp[i] = dp[i] + dp[i - one] + dp[i - zero]
dp[low] ~ dp[high] 의 합을 구해주면 됩니다.
*/

class Solution {
public:
    const int MOD = 1e9 + 7;
    int countGoodStrings(int low, int high, int zero, int one) {
        int dp[100001] = {0};
        dp[0] = 1;
        for(int i=1;i<=high; i++) {
            if(i >= one) dp[i] = (dp[i] + dp[i - one]) % MOD;
            if(i >= zero) dp[i] = (dp[i] + dp[i - zero]) % MOD;
        }

        int res = 0;
        for(int i=low; i<=high; i++) {
            res = (res + dp[i]) % MOD;
        }
        return res;
    }
};
