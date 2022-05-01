/*
뒤에서부터 검사하며 백스페이스로 인해 지워지는 문자는 건너뛰어줍니다.
*/

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1, j = t.size() - 1;
        int c1 = 0, c2 = 0;
        while(i >= 0 && j >= 0) {
            while(s[i] == '#') c1++, i--;
            while(t[j] == '#') c2++, j--;
            if(c1 > 0) {
                c1--, i--;
                continue;
            }
            if(c2 > 0) {
                c2--, j--;
                continue;
            }
            if(s[i--] != t[j--]) return false; 
        }
        for(; i >= 0; i--) {
            if(s[i] == '#') c1++;
            else if(c1-- <= 0) break;
        }
        for(; j >= 0; j--) {
            if(t[j] == '#') c2++;
            else if(c2-- <= 0) break;
        }
        return i < 0 && j < 0;
    }
};