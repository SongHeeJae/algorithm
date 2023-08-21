/*
패턴의 길이가 i일 때, 반복되는 동일한 패턴으로 s를 만들 수 있는지 확인해주었습니다.
*/

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int sz = s.size();
        for(int i=1; i<sz; i++) {
            if(sz % i != 0) continue;
            bool flag = true;
            for(int j=i; j<sz; j++) {
                if(s[j % i] != s[j]) {
                    flag = false;
                    break;
                }
            }
            if(flag) return true;
        }

        return false;
    }
};
