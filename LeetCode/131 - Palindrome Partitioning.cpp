/*
s를 파티션한 palindrome 문자열을 임시 벡터에 저장하고, 다음 인덱스부터 다시 파티셔닝해나가는 과정을 재귀적으로 수행해줍니다.
*/

class Solution {
public:
    vector<vector<string>> result;
    vector<string> temp;

    vector<vector<string>> partition(string s) {
        partition(s, 0);
        return result;
    }

    void partition(string& s, int idx) {
        if(idx == s.size()) {
            result.push_back(temp);
            return;
        }

        for(int i=idx; i<s.size(); i++) {
            if(!isPalindrome(s, idx, i)) continue;
            temp.push_back(s.substr(idx, i - idx + 1));
            partition(s, i + 1);
            temp.pop_back();
        }
    }

    bool isPalindrome(string& s, int l, int r) {
        while(l < r)
            if(s[l++] != s[r--]) return false;
        return true;
    }
};
