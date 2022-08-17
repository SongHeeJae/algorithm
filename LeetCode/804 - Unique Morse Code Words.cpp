/*
변환된 단어를 set에 저장하여 중복을 제거해주었습니다.
*/

class Solution {
public:
    string morse[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    
    set<string> transWords;
    int uniqueMorseRepresentations(vector<string>& words) {
        for(string& word : words) {
            string temp = "";
            for(char w : word) temp += morse[w - 'a'];
            transWords.insert(temp);
        }
        return transWords.size();
    }
};
