/*
t를 순차적으로 탐색하면서 s의 현재 문자가 t에 속해있다면 다음 문자를 검사해줍니다.
s의 모든 문자를 검사할 수 있었다면 subsequence입니다.
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sl = s.size(), tl = t.size();
        if(sl > tl) return false;

        int si = 0, ti = 0;
        while(si < sl && ti < tl) {
            if(s[si] == t[ti]) si++;
            ti++;
        }
        return si == sl;
    }
};
