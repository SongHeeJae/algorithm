/*
dp를 이용하여 풀 수 있었습니다.

s[x] ~ s[y]는 문자열 s의 인덱스 x에서 y까지의 substring이라고 하겠습니다.
dp[i][j] = s[i] ~ s[j]가 palindrome인지 저장해줄 것입니다.
길이 1~2의 palindrome 여부에 대해서 미리 초기화해줍니다.
길이 1의 substring은 모두 palindrome이고, 길이 2의 substring은 두 문자가 같을 때 palindrome입니다.

s[x] ~ s[y]가 palindrome인지 판별하려면,
s[x + 1] ~ s[y - 1]가 이미 palindrome이고, s[x] == s[y] 인지 판별해주면 됩니다.
즉, dp[x][y] = dp[x + 1][y - 1] && s[x] == s[y]가 됩니다.

이미 판별된 값을 이용해야하므로 바깥 반복문은 역순으로 수행해주었습니다.
*/

class Solution {
public:
    bool dp[1001][1001] = { false };
    int countSubstrings(string s) {
        int cnt = s.size();
        for(int i=s.size() - 1; i>=0; i--) {
            dp[i][i] = true;
            cnt += dp[i][i + 1] = s[i] == s[i + 1];
            for(int j=i+2; j<s.size(); j++)
                cnt += dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];  
        }
        return cnt;
    }
};