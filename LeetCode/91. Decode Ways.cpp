/*
한자릿수 또는 두자릿수로 그룹핑해주었을 때, s를 온전하게 디코딩 할 수 있는지 검사해줍니다. 
*/

class Solution {
public:
    int dp[100];

    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        return numDecodings(s, 0);
    }

    int numDecodings(string& s, int idx) {
        if(idx == s.size()) return 1;

        if(dp[idx] != -1) return dp[idx];

        int& c = dp[idx];
        c = 0;

        if(s[idx] == '0') return c;

        // 한자릿수 디코딩
        c += numDecodings(s, idx + 1); 

        if(idx >= s.size() - 1) return c;

        // 두자릿수 디코딩
        if(s[idx] == '1') {
            c += numDecodings(s, idx + 2);
        } else if(s[idx] == '2' && s[idx + 1] <= '6') {
            c += numDecodings(s, idx + 2);
        }
     
        return c;
    }
};
