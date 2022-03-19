class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        map<char, char> m = { {')', '('}, {'}', '{'}, {']', '['} };
        
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stk.push(s[i]);
            } else {
                if(stk.empty() || stk.top() != m[s[i]]) return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};

/*
스택을 이용하여 괄호의 짝이 맞는지 확인해주었습니다.
*/