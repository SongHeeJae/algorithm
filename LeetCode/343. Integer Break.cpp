/*
n을 쪼갠 수들의 곱을 최대화할 수 있는 경우를 찾아줍니다.
dp[n] = max({dp[n], i * dp[n - i], i * (n - i)} // 1 <= i <= n/2
*/

class Solution {
public:
    int dp[59] = {0};

    int integerBreak(int n) {
        if(n == 2) return 1;
        if(dp[n]) return dp[n];

        for(int i=1; i<=n/2; i++) {
            dp[n] = max({dp[n], i * integerBreak(n - i), i * (n - i)});
        }

        return dp[n];
    }

};


