/*
s가 t로, t가 s로 대치되는 최초 문자를 기억해주고, 서로 대치되는 문자에 모순이 생기는지 확인해줍니다.
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char sm[256] = {0}, tm[256] = {0};
        for(int i=0; i<s.size(); i++) {
            if(sm[s[i]] == 0) sm[s[i]] = t[i];
            if(tm[t[i]] == 0) tm[t[i]] = s[i];
            if(sm[s[i]] != t[i] || tm[t[i]] != s[i]) return false;
        }
        return true;
    }
};
