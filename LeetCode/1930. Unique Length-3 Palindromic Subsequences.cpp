/*
길이 3의 팰린드롬은, 양 끝 문자가 동일하면 됩니다.
각 문자가 처음/끝에 등장하는 지점을 찾아주고, 해당 지점 사이에서 고유한 문자의 개수를 구해주면 됩니다.
*/

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int left[26] = {0}, right[26] = {0};

        for(int i=0; i<s.size(); i++) {
            left[s[s.size() - i - 1] - 'a'] = s.size() - i - 1;
            right[s[i] - 'a'] = i;
        }

        int res = 0;
        for(int i=0; i<26; i++) {
            res += countUniqueLetters(s, left[i] + 1, right[i] - 1);
        }
        return res;
    }

private:
    int countUniqueLetters(string& s, int l, int r) {
        unordered_set<char> letters;
        for(int i=l; i<=r; i++) letters.insert(s[i]);
        return letters.size();
    }
};
