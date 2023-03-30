/*
모든 경우를 탐색하며 dp를 이용하였습니다.
일단 s1과 s2를 이루는 알파벳의 개수가 동일하지 않으면, 동일한 문자열을 만들 수 없습니다.
dp[str] = dp[(s1의 substring + s2의 substring)] = 두 문자열을 동일하게 만들 수 있는지 여부를 저장해줍니다.
두 문자열이 있고, i번째까지 문자열을 슬라이스하여 x와 y를 만든다면,
dp[s1 + s2]
= (dp[s1.substr(0, i) + s2.substr(0, i)] && dp[s1.substr(i) + s2.substr(i)]) // swap하지 않은 경우
  || (dp[s1.substr(0, i) + s2.substr(n - i)] && dp[s1.substr(i) + s2.substr(0, n - i)]) // swap한 경우

예를 들어,
s1 = abcde
s2 = fghij
두 문자열(각 알파벳은 임의의 문자)이 있고, i == 1일 때에는 다음과 같을 것입니다.
swap 하지 않은 경우인, dp[a + f] && dp[bcde + ghji] 가 true 이거나,
swap 한 경우인, dp[a + j] && dp[bcde + fghj] 가 true 라면,
dp[abcde + fghij]도 true가 됩니다.
*/

class Solution {
public:
    unordered_map<string, bool> dp;
    int cnt[26] = {0};

    bool isScramble(string s1, string s2) {
        if(s1 == s2) return true;
        
        memset(cnt, 0, sizeof(cnt));
        for(char s : s1) cnt[s - 'a']++;
        for(char s : s2) cnt[s - 'a']--;
        for(int i=0; i<26; i++)
            if(cnt[i]) return false;

        string key = s1 < s2 ? s1 + s2 : s2 + s1;
        if(dp.find(key) != dp.end()) return dp[key];

        int n = s1.size();
        for(int i=1; i<n; i++) {
            string x1 = s1.substr(0, i);
            string y1 = s1.substr(i);

            string x21 = s2.substr(0, i);
            string y21 = s2.substr(i);

            string x22 = s2.substr(0, n - i);
            string y22 = s2.substr(n - i);

            if(isScramble(x1, x21) && isScramble(y1, y21)
                || isScramble(x1, y22) && isScramble(y1, x22)) {
                return dp[key] = true;
            }
        }

        return dp[key] = false;
    }
};
