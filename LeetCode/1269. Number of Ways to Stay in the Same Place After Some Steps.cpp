/*
우측으로 1칸 이동한 경우, 좌측으로 1칸 이동한 경우, 제자리에 남아있는 경우를 모두 검사해주었습니다.
중간 결과는 재사용해줍니다.
dp[steps][idx] = dp[steps - 1][idx + 1] + dp[steps - 1][idx - 1] + dp[steps - 1][idx] 
*/

class Solution {
public:
    int dp[501][501];
    const int MOD = 1e9 + 7;

    int numWays(int steps, int arrLen) {
        memset(dp, -1, sizeof(dp));
        return numWays(steps, arrLen, 0);
    }

    int numWays(int steps, int arrLen, int idx) {
        if(steps == 0) return idx == 0;
        if(idx < 0 || idx >= arrLen) return 0;

        int& cnt = dp[steps][idx];
        if(cnt != -1) return cnt; 
        return cnt = (
            (numWays(steps - 1, arrLen, idx + 1)
                + numWays(steps - 1, arrLen, idx - 1)) % MOD
            + numWays(steps - 1, arrLen, idx) 
        ) % MOD;
    }
};
