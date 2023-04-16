class Solution {
public:
    const int MOD = 1000000007;
    int dp[1000][1000];
    int cnt[1000][26];

    int numWays(vector<string>& words, string target) {
        memset(dp, -1, sizeof(dp));
        memset(cnt, 0, sizeof(cnt));

        for(int i=0; i<words.size(); i++) {
            for(int j=0; j<words[i].size(); j++) {
                cnt[j][words[i][j] - 'a']++;
            }
        }

        return dfs(words, 0, target, 0);
    }

    long long dfs(vector<string>& words, int j, string& target, int k) {
        if(k == target.size()) return 1;
        if(j == words[0].size()) return 0;

        if(dp[j][k] != -1) return dp[j][k];

        return dp[j][k] = (
            cnt[j][target[k] - 'a'] * dfs(words, j + 1, target, k + 1)
                + dfs(words, j + 1, target, k)
        ) % MOD;
    }
};
