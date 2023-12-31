/*
각 문자가 처음 나온 위치를 기억해두고, 동일한 두 문자 사이 서브스트링의 최대 길이를 업데이트해줍니다.
*/

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int idx[26], res = 0;
        memset(idx, -1, sizeof(idx));
        for(int i=0; i<s.size(); i++) {
            if(idx[s[i] - 'a'] == -1) {
                idx[s[i] - 'a'] = i;
            } else {
                res = max(res, i - idx[s[i] - 'a']);
            }
        }
        return res - 1;
    }
};
