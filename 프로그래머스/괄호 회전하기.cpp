#include <string>
#include <vector>
#include <stack>
using namespace std;

bool isValid(string& s) {
    stack<char> stk;
    for(int i=0; i<s.size(); i++) {
        if(s[i] == '[' || s[i] == '{' || s[i] == '(') stk.push(s[i]);
        else {
            if(stk.empty() || stk.top() != (s[i] == ']' ? '[' : (s[i] == ')' ? '(' : '{'))) return false;
            stk.pop();
        } 
    }
    return stk.empty();
}

void rotate(string& s) {
    s = s.substr(1) + s[0];
}

int solution(string s) {
    int answer = isValid(s);
    for(int i=1; i<s.size(); i++) {
        rotate(s);
        answer += isValid(s);
    }
    return answer;
}