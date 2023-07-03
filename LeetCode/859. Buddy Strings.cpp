/*
s와 goal의 길이가 다르면, false를 반환해줍니다.
s와 goal을 순회하면서, 다른 문자가 나오는 인덱스 i와 j(i < j)를 찾아줍니다.
이 때, 2개 초과 또는 미만의 인덱스 문자가 다르다면, false를 반환해줍니다.
두 문자열이 동일하다면(i == -1), 동일한 문자가 2개 이상 있어야 swap해도 동일한 문자열을 유지할 수 있습니다.
두 문자열이 다르다면, s[i] == goal[j] && s[j] == goal[i] 인지 검사해줍니다.
*/

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size()) return false;
        int i = -1, j = -1;
        int cnt[26] = {0}, cntMax = 0;
        for(int k = 0; k < s.size(); k++) {
            if(s[k] == goal[k]) cntMax = max(cntMax, ++cnt[s[k] - 'a']);
            else if(i == -1) i = k;
            else if(j == -1) j = k;
            else return false;
        }
        if (i == -1 && cntMax > 1) return true;
        if (j == -1) return false;
        return s[i] == goal[j] && s[j] == goal[i];
    }
};

