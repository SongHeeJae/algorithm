/*
ch의 index를 찾아준 뒤 뒤집어줍니다.
*/

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int idx = find(word, ch);
        if(idx == -1) return word;
        for(int i=0; i<=idx/2; i++) swap(word[i], word[idx-i]);
        return word;
    }

    int find(string& str, char ch) {
        for(int i=0; i<str.size(); i++) {
            if(str[i] == ch) return i;
        }
        return -1;
    }
};
