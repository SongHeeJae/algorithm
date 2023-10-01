/*
각 단어에 대한 시작/끝 인덱스를 구해주고, 해당 범위에 대해서 역순으로 뒤집어줍니다. 
*/

class Solution {
public:
    string reverseWords(string s) {
        int j = 0;
        for(int i=1; i<s.size(); i++) {
            if(s[i] == ' ') {
                reverse(s, j, i - 1);
                j = i + 1;
            }
        }
        reverse(s, j, s.size() - 1);
        return s;
    }

    void reverse(string& s, int l, int r) {
        int sz = (l + r) / 2 - l;
        for(int i=0; i<=sz; i++) {
            swap(s[l + i], s[r - i]);
        }
    }
};
