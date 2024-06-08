/*
투포인터를 이용하여 풀었습니다
s를 순회하면서 s[i] == t[j]라면 j의 포인터를 올려줍니다.
j까지 이동한 t의 prefix는 s의 subsequence로 활용할 수 있었으므로, t.size() - j만큼 s에 문자를 덧붙여주면됩니다.
*/

class Solution {
public:
    int appendCharacters(string s, string t) {
        int i=0, j=0;
        while(i < s.size() && j < t.size()) {
            if(s[i] == t[j]) j++;
            i++;
        }
        return t.size() - j;
    }
};
