class Solution {
public:
    int dp[100000];
    const int MOD = 1e9 + 7;

    int numberOfArrays(string s, int k) {
        memset(dp, -1, sizeof(dp));
        return dfs(s, k, 0);
    }

    int dfs(string& s, int k, int idx) {
        if(dp[idx] != -1) return dp[idx];
        
        if(idx == s.size()) return 1;
        
        dp[idx] = 0;
        long long val = 0;
        for(int i=idx; i<s.size(); i++) {
            val = val * 10 + (s[i] - '0');
            if(val < 1 || val > k) break;
            dp[idx] += dfs(s, k, i + 1);
            dp[idx] %= MOD;
        }
        return dp[idx];
    }
};
