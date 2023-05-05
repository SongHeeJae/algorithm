/*
슬라이딩 윈도우 문제였습니다.
문자열을 탐색하면서 연속된 부분 문자열의 모음 개수를 저장해줍니다.
i번 문자를 탐색해야할 때 부분 문자열의 길이가 k를 초과하면, (i-k)번 문자의 모음 여부를 확인하여, 검사되는 부분 문자열의 길이를 k로 유지해줍니다.
*/

class Solution {
public:
    int maxVowels(string s, int k) {
        int res = 0, cnt = 0;
        for(int i=0; i<s.size(); i++) {
            if(i >= k) cnt -= isVowel(s[i - k]);
            cnt += isVowel(s[i]);
            res = max(res, cnt);
        }
        return res;
    }

    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};
