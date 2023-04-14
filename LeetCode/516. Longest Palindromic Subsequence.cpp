/*
dp[i][j] = s[i]~s[j]에서의 Longest Palindromic Subsequence 최대 길이를 저장해줍니다.
s[i] == s[j] 라면, 새로운 2개의 문자는 palindrome이 되므로, dp[i][j] = dp[i + 1][j - 1] + 2.
그렇지 않다면, dp[i][j] = max(dp[i + 1][j], dp[i][j - 1])이 됩니다.
*/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int dp[1000][1000] = {0};

        for(int i=s.size() - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for(int j = i + 1; j < s.size(); j++) {
                if(s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
                
            }
        }

        return dp[0][s.size() - 1];
    }
};
