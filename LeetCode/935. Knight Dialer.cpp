/*
dp[i][n] = sum(dp[j][n - 1]) // 0 <= i <= 9, j = i에서 이동 가능한 다이얼
위 점화식을 이용하여 sum(dp[0 .. 9][n])를 구해주면 됩니다.
*/

class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<vector<int>> path = {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {0, 3, 9},
        { },
        {0, 1, 7},
        {2, 6},
        {1, 3},
        {2, 4}
    };
    
    int knightDialer(int n) {
        int cnt[10] = {1,1,1,1,1,1,1,1,1,1};
        int tcnt[10];
        for(int i=1; i<n; i++) {
            for(int j=0; j<10; j++) {
                tcnt[j] = 0;
                for(int p : path[j]) {
                    tcnt[j] += cnt[p];
                    tcnt[j] %= MOD;
                }
            }

            for(int j=0; j<10; j++) {
                cnt[j] = tcnt[j];
            }
        }

        int res = 0;
        for(int i=0; i<10; i++) {
            res += cnt[i];
            res %= MOD;
        }
        return res;
    }
};
