/*
dp를 이용하여 풀었습니다.
s[i] ~ s[j]가 palindromic substring이라면, dp[i][j]는 문자열의 길이를 저장해줍니다.
dp[i - 1][j + 1] = s[i - 1] == s[j + 1] ? dp[i][j] + 2 : 0
길이가 1인 substring 부터 검사해주었습니다. 
*/

class Solution {
public:
    int dp[1000][1000] = {0};
    string longestPalindrome(string s) {
        int l = 0, r = 0, mx = 1;
        for(int i=0; i<s.size(); i++) {
            dp[i][i] = 1;
        }
        for(int i=0; i<s.size() - 1; i++) {
            if(s[i] == s[i + 1]) {
                dp[i][i + 1] = mx = 2;
                l = i, r = i + 1;
            }
        }
        
        for(int i=0; i < s.size(); i++) {
            for(int j=0; i + j < s.size(); j++) {
                if(!(j - 1 >= 0 && j + i + 1 < s.size())) continue;
                if(s[j - 1] == s[j + i + 1] && dp[j][j + i]) {
                    dp[j - 1][j + i + 1] = dp[j][j + i] + 2;
                    if(dp[j - 1][j + i + 1] > mx) {
                        mx = dp[j - 1][j + i + 1];
                        l = j - 1, r = j + i + 1;
                    }
                }
            }
        }

        return s.substr(l, r - l + 1);
    }
};
