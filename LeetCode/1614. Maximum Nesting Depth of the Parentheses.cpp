/*
문자열은 유효한 괄호 쌍이므로, 열린 괄호를 만나면 depth가 증가, 닫힌 괄호를 만나면 depth를 감소해줍니다.
최대 depth를 찾아줍니다.
*/

class Solution {
public:
    int maxDepth(string s) {
        int d = 0, res = 0;
        for(char c : s) {
            if(c == '(') d++;
            else if(c == ')') res = max(res, d--); 
        }
        return res;
    }
};
