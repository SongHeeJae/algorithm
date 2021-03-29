#include <string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    stack<char> stk;
    for(int i=0; i<s.size(); i++) {
        char ch = s[i];
        if(ch == '(') stk.push(ch);
        else {
            if(stk.empty()) return false;
            stk.pop();
        }
    }
    if(stk.empty()) return true;
    else return false;
}