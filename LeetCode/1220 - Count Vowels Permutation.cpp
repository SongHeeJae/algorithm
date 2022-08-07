/*
dp를 이용하여 풀 수 있었습니다.

'a'의 이전 문자는 'e', 'u', 'i'가 올 수 있습니다.
'e'의 이전 문자는 'a', 'i'가 올 수 있습니다.
'i'의 이전 문자는 'e', 'o'가 올 수 있습니다.
'o'의 이전 문자는 'i'가 올 수 있습니다.
'u'의 이전 문자는 'o', 'i'가 올 수 있습니다.

dp[i][j] = 길이가 i이고, 문자열의 마지막 알파벳이 j일 때의 가능한 문자열의 개수를 저장해줍니다.
dp[i]['a'] = dp[i - 1]['e'] + dp[i - 1]['u'] + dp[i - 1]['i'];
dp[i]['e'] = dp[i - 1]['a'] + dp[i - 1]['i'];
dp[i]['i'] = dp[i - 1]['e'] + dp[i - 1]['o'];
dp[i]['o'] = dp[i - 1]['i'];
dp[i]['u'] = dp[i - 1]['o'] + dp[i - 1]['i']; 가 됩니다.

(10^9 + 7)의 나머지를 구해주면 되는데,
dp 변수를 int 형으로 선언했다면, 세 항을 더할 때에 오버플로가 발생할 수 있습니다.
잦은 나머지 연산이 부담된다면, 더 큰 자료형을 사용하는 방법도 있을 것입니다.
이 점에 유의하며 문자열의 개수를 구해주면 됩니다.
*/


class Solution {
public:
    const int MOD = 1000000007;
    const int A = 0, E = 1, I = 2, O = 3, U = 4;
    
    int dp[20001][5] = {0};
    
    int countVowelPermutation(int n) {
        for(int i=0; i<5; i++) dp[1][i] = 1;
        
        for(int i=2 ; i<=n; i++) {
            dp[i][A] = mod(mod(dp[i - 1][E] + dp[i - 1][U]) + dp[i - 1][I]);
            dp[i][E] = mod(dp[i - 1][A] + dp[i - 1][I]);
            dp[i][I] = mod(dp[i - 1][E] + dp[i - 1][O]);
            dp[i][O] = dp[i - 1][I];
            dp[i][U] = mod(dp[i - 1][O] + dp[i - 1][I]);
        }
        
        return mod(mod(mod(dp[n][A] + dp[n][E]) + mod(dp[n][I] + dp[n][O])) + dp[n][U]);
    }
    
    int mod(int val) {
        return val % MOD;
    }
};
