/*
첫번째로 등장하는 palindrome을 찾아줍니다.
*/

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(string& word : words)
            if(isPalindrome(word)) return word;
        return "";
    }

    bool isPalindrome(string& s) {
        for(int i=0; i<s.size() / 2; i++)
            if(s[i] != s[s.size() - 1 - i]) return false;
        return true;
    }
};
