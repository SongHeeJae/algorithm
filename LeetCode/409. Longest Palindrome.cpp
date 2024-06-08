/*
짝수 개의 문자는 모두 palindrome으로 만들 수 있고, 1개의 문자는 가운데에 넣을 수 있습니다.
*/

class Solution {
public:
    int longestPalindrome(string s) {
        int cnt['z' + 1] = {0};
        for(char c : s) cnt[c]++;
        int res = 0;
        bool hasOdd = false;
        for(int i='A'; i<='z'; i++) {
            bool odd = cnt[i] % 2;
            if(odd) hasOdd = true;
            res += cnt[i] - odd;
        }
        return res + hasOdd;
    }
};
