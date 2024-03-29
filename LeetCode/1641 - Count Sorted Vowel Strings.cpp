/*
dp를 이용하여 풀 수 있었습니다.
dp[i][j] = (n == i)이고, 첫 문자가 j('a', 'e', 'i', 'o', u'를 숫자로 취급)일 때, 가능한 문자열의 수를 저장해주면 됩니다.
초기에는 dp[1]['a'~'e'] = 1로 초기화됩니다.
dp[2]['a'] = dp[1]['a'] + ... + dp[1]['u']
dp[2]['e'] = dp[1]['e'] + ... + dp[1]['u']
dp[2]['i'] = dp[1]['i'] + ... + dp[1]['u']
...
형태로 채워나가면 됩니다.
길이가 n이고 첫 문자가 'a' 라면,
길이가 n-1로 만들어지는 모든 문자열 앞에 'a'를 붙여주면 되기 때문입니다.

바로 이전 값만 있어도 되므로, 5 크기의 배열만 선언해주었습니다.
*/

class Solution {
public:
    int countVowelStrings(int n) {
        int dp[5] = {1,1,1,1,1};
        for(int i=2;i<=n; i++)
            for(int j=3; j>=0; j--) dp[j] += dp[j + 1];
        return dp[0] + dp[1] + dp[2] + dp[3] + dp[4];
    }
};