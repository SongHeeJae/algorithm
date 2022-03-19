class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stk;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '(') stk.push(i);
            else if(s[i] == ')') {
                if(stk.empty()) continue;
                s[i] = 'C';
                s[stk.top()] = 'O';
                stk.pop();
            }
        }
        
        string result = "";
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '(' || s[i] == ')') continue;
            result.push_back(s[i] == 'O' ? '(' : (s[i] == 'C' ? ')' : s[i]));
        }
        return result;
    }
};

/*
스택을 이용하여 풀이하였습니다.
문자열을 순회하면서 올바른 괄호 쌍을 표시해줍니다.
즉, 기존 문자열에 남게 되는 괄호 쌍들은 올바르지 않습니다.
해당 괄호 쌍들을 제외해주면 되었습니다.
*/