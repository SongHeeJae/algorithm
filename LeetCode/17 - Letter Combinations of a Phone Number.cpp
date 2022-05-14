/*
각 digit에 매핑되는 letters를 전처리해두고, combination을 구해주었습니다.
*/

class Solution {
public:
    string letters[10] = {"", "", "abc", "def", "ghi", "jkl",
                       "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ret;
    string comb = "";
    
    vector<string> letterCombinations(string digits) {
        if(digits.size()) letterCombinationsInternal(digits, 0);
        return ret;
    }
    
private:
    void letterCombinationsInternal(string& digits, int idx) {
        if(idx == digits.size()) {
            ret.push_back(comb);
            return;
        }
        
        int lettersIdx = digits[idx] - '0';
        int sz = letters[lettersIdx].size();
        for(int i=0; i<sz; i++) {
            comb.push_back(letters[lettersIdx][i]);
            letterCombinationsInternal(digits, idx + 1);
            comb.pop_back();
        }
    }
};