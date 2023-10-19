/*
각 문자열에 대해 투포인터를 이용하여 backspace가 적용되었을 때의 문자열과 길이를 구해줍니다.
O(1)의 공간과 O(n)의 시간으로 풀 수 있었습니다.
*/

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int sSize = removeBackspaceAndGetSize(s);
        int tSize = removeBackspaceAndGetSize(t);
            
        if (sSize != tSize) return false;
        for(int i=0; i<sSize; i++)
            if(s[i] != t[i]) return false;
        return true;
    }

private:
    int removeBackspaceAndGetSize(string& str) {
        int sz = 0;
        for(char c : str)
            if(c == '#') sz -= sz > 0;
            else str[sz++] = c;
        return sz;
    }
};
