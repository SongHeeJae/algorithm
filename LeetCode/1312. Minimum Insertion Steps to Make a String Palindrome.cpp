/*
dp와 투포인터를 이용하였습니다.
dp[l][r] = s[l] ~ s[r]인 부분 문자열을 palindrome으로 만드는 최소 횟수를 저장해줍니다.
s[l] == s[r]라면, 새로운 문자를 추가하지 않아도 됩니다. dp[l][r] = dp[l + 1][r- 1]
s[l] != s[r]라면, 새로운 문자를 부분 문자열의 좌측 또는 우측에 추가해줘야합니다. dp[l][r] = min(dp[l + 1][r], dp[l][r - 1]) + 1
*/

class Solution {
public:
    int dp[500][500];
    int minInsertions(string s) {
        memset(dp, -1, sizeof(dp));
        return dfs(s, 0, s.size() - 1);
    }

    int dfs(string& s, int l, int r) {
        if(l >= r) return 0;

        if(dp[l][r] != -1) return dp[l][r];

        return dp[l][r] = (s[l] == s[r]) ?
            dfs(s, l + 1, r - 1) :
            1 + min(dfs(s, l + 1, r), dfs(s, l, r - 1));
    }
};
