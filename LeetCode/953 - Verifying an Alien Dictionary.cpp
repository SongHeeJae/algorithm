/*
각 알파벳의 순서를 저장하여 비교 함수를 만들어줍니다.
word를 순차적으로 확인하며 비교 함수를 수행해줍니다.
*/

class Solution {
public:
    int ord[26];
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i=0; i<26; i++) 
            ord[order[i] - 'a'] = i;

        for(int i=1; i<words.size(); i++)
            if(!compare(words[i - 1], words[i])) return false;
        return true;
    }
    
    bool compare(string& a, string& b) {
        for(int i=0; i<a.size() && i<b.size(); i++)
            if(a[i] != b[i]) return ord[a[i] - 'a'] < ord[b[i] - 'a'];
        return a.size() <= b.size();
    }
};
