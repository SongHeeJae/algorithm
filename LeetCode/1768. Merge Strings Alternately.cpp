/*
선언한 문자열에 word1과 word2를 번갈아가면서 삽입해줍니다. 한 문자열이 끝에 다다르면, 남은 문자열을 모두 삽입해줍니다.
*/

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res = "";
        int i = 0, sz = min(word1.size(), word2.size());
        while(i < sz) {
            res.push_back(word1[i]);
            res.push_back(word2[i++]);
        }
        return res + word1.substr(i) + word2.substr(i);
    }
};
