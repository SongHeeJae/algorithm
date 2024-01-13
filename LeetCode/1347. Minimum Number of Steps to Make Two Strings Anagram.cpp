/*
s와 t의 각 문자 개수를 구해줍니다.
t의 문자가 이미 s의 문자라면 그대로 두고, s의 문자가 아니면 치환해야하므로 그 개수를 모두 구해줍니다.
*/

class Solution {
public:
    int minSteps(string s, string t) {
        int cnt[26] = {0};
        for(int i=0; i<s.size(); i++) {
            cnt[s[i] - 'a']++;
            cnt[t[i] - 'a']--;
        }

        int res = 0;
        for(int i=0; i<26; i++) {
            if(cnt[i] < 0) res += -cnt[i];
        }
        return res;
    }
};
