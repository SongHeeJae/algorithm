/*
모든 문자열의 prefix를 순차적으로 검사하며, 공통된 부분을 찾아줍니다.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        int i = 0;
        while(1) {
            char c = strs[0][i];
            for(string& str : strs) {
                if(i >= str.size() || c != str[i]) return res;
            }
            res.push_back(strs[0][i++]);
        }
        return res;
    }
};
